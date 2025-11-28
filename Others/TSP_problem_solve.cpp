#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;

/*
NN(Nearest Neighbor) + 2-opt

<입력>
1 x1 y1
2 x2 y2
...
n xn yn
EOF

<출력>
NN으로 구한 경로 합
2-opt로 구한 경로 합
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

    // NN 실행
    vector<int> path(n);
    do_NN(path, dist);
    double NN_sum_path = get_sum_path(path, dist);

    // 2-opt 실행
    do_two_opt(path, dist);
    double two_opt_sum_path = get_sum_path(path, dist);

    auto end = chrono::high_resolution_clock::now();

    cout << "NN 경로 합: " << NN_sum_path << "\n";
    cout << "2-opt 후 경로 합: " << two_opt_sum_path << "\n";

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "소요 시간: " << duration.count() << " ms" << endl;

    return 0;
}