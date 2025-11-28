#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;

/*
<입력>
1 x1 y1
2 x2 y2
...
n xn yn
EOF

<출력>
최종 경로 합
소요 시간
*/

const double INF { 1e9 };

struct Point {
    int id;
    double x, y;
};

// 유클리드 거리 계산
double get_distance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// 경로상의 거리 합 계산
double get_sum_path(const vector<int>& path, const vector<vector<double>>& dist) {
    double sum = 0.0;
    int n = path.size();
    for (int i = 0; i < n; i++) {
        sum += dist[path[i]][path[(i + 1) % n]];
    }
    return sum;
}

// 그리드 기반의 클러스터링
void clustering(vector<vector<int>>& clusters, const vector<Point>& points) {
    int n = points.size();
    double x_min = points[0].x, x_max = points[0].x;
    double y_min = points[0].y, y_max = points[0].y;
    for (const auto& p : points) {
        x_min = min(x_min, p.x);
        x_max = max(x_max, p.x);
        y_min = min(y_min, p.y);
        y_max = max(y_max, p.y);
    }

    int target_cell_size = 10;
    int gridX = max(1, int((x_max - x_min) / target_cell_size));
    int gridY = max(1, int((y_max - y_min) / target_cell_size));
    double cellWidth = (x_max - x_min) / gridX;
    double cellHeight = (y_max - y_min) / gridY;

    clusters.resize(gridX * gridY);

    for (int i = 0; i < n; i++) {
        int cellX = min(int((points[i].x - x_min) / cellWidth), gridX - 1);
        int cellY = min(int((points[i].y - y_min) / cellHeight), gridY - 1);
        int cell_id = cellY * gridX + cellX;
        clusters[cell_id].push_back(i);
    }
}

// NN 방식 적용
void do_NN(vector<int>& path, const vector<vector<double>>& dist) {
    int n = dist.size();
    int current = 0;
    
    path.push_back(current);

    vector<bool> visited(n, false);
    visited[current] = true;

    for (int i = 1; i < n; i++) {
        double min_dist = INF;
        int next = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[current][j] < min_dist) {
                min_dist = dist[current][j];
                next = j;
            }
        }
        current = next;
        path.push_back(current);
        visited[current] = true;
    }
}

// 2-opt 방식 적용
void do_two_opt(vector<int>& path, const vector<vector<double>>& dist) {
    int n = path.size();
    bool can_improve = true;

    while (can_improve) {
        can_improve = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = path[i];
                int b = path[(i + 1) % n];
                int c = path[j];
                int d = path[(j + 1) % n];

                double dist_difference = (dist[a][c] + dist[b][d]) - (dist[a][b] + dist[c][d]);
                if (dist_difference < 0.0) {
                    int start = i + 1;
                    int end = j;
                    while (start < end) {
                        swap(path[start], path[end]);
                        start++;
                        end--;
                    }
                    can_improve = true;
                }
            }
        }
    }
}

// Held-Karp DP 적용
void do_held_karp_dp(vector<int>& path, const vector<vector<double>>& dist) {
    int n = path.size();
    if (n <= 1) return;

    int FULL = (1 << n) - 1;
    vector<vector<double>> dp(1 << n, vector<double>(n, INF));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));

    dp[1][0] = 0;

    for (int mask = 1; mask <= FULL; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                double new_dist = dp[mask][u] + dist[path[u]][path[v]];
                if (new_dist < dp[mask | (1 << v)][v]) {
                    dp[mask | (1 << v)][v] = new_dist;
                    parent[mask | (1 << v)][v] = u;
                }
            }
        }
    }

    // 최종 경로
    double best = INF;
    int last = -1;
    for (int i = 1; i < n; i++) {
        double d = dp[FULL][i] + dist[path[i]][path[0]];
        if (d < best) {
            best = d;
            last = i;
        }
    }

    // 경로 역추적
    vector<int> new_path(n);
    int mask = FULL;
    for (int i = n - 1; i >= 0; --i) {
        new_path[i] = path[last];
        int temp = parent[mask][last];
        mask ^= (1 << last);
        last = temp;
    }
    path = new_path;
}

// 클러스터별로 처리
void processing(vector<vector<int>>& clusters, const vector<vector<double>>& dist) {
    for (auto& cluster : clusters) {
        if (cluster.empty()) continue;
        if (cluster.size() <= 16) {
            do_held_karp_dp(cluster, dist);
        } else {
            do_NN(cluster, dist);
        }
    }
}

// 모든 클러스터 다시 합치면서 경로 확정
void joining(vector<vector<int>>& clusters, const vector<vector<double>>& dist, vector<int>& path) {
    vector<bool> used(clusters.size(), false);
    int n = clusters.size();

    int start = 0;
    while (start < n && clusters[start].empty()) start++;
    if (start == n) return;

    path.insert(path.end(), clusters[start].begin(), clusters[start].end());
    used[start] = true;

    int current_cluster = start;
    while (true) {
        double min_dist = INF;
        int next_cluster = -1;
        for (int i = 0; i < n; i++) {
            if (used[i] || clusters[i].empty()) continue;
            double d = dist[path.back()][clusters[i][0]];
            if (d < min_dist) {
                min_dist = d;
                next_cluster = i;
            }
        }
        if (next_cluster == -1) break;

        path.insert(path.end(), clusters[next_cluster].begin(), clusters[next_cluster].end());
        used[next_cluster] = true;
        current_cluster = next_cluster;
    }
}

int main() {
    // 파일 입력
    ifstream infile("berlin52_TSP.txt");
    if (!infile) {
        cerr << "파일 열기 실패\n";
        return 1;
    }

    vector<Point> points;
    int id;
    double x, y;
    while (infile >> id >> x >> y) {
        points.push_back({id - 1, x, y});
    }
    infile.close();

    // Distance Matrix 구성
    int n = points.size();
    vector<vector<double>> dist(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = get_distance(points[i], points[j]);
        }
    }

    auto start = chrono::high_resolution_clock::now();

    // 클러스터링
    vector<vector<int>> clusters;
    clustering(clusters, points);

    // 클러스터별로 처리
    processing(clusters, dist);

    // 클러스터 다시 합치기 
    vector<int> path(n);
    joining(clusters, dist, path);
    do_two_opt(path, dist);

    auto end = chrono::high_resolution_clock::now();

    double final_sum_paths = get_sum_path(path, dist);
    cout << "최종 경로 합: " << final_sum_paths << "\n";

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "소요 시간: " << duration.count() << " ms" << endl;

    return 0;
}