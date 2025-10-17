#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;

void floyd(int n, vector<vector<int>>& graph) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (i != k) {
                for (int j = 0; j < n; j++) {
                    if (j != i && j != k) {
                        int temp = graph[i][k] + graph[k][j];
                        graph[i][j] = graph[i][j] > temp ? temp : graph[i][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) graph[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (c < graph[a-1][b-1]) graph[a-1][b-1] = c;
    }

    floyd(n, graph);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = graph[i][j];
            if (k == INF) k = 0;
            printf("%d ", k);
        }
        printf("\n");
    }

    return 0;
}