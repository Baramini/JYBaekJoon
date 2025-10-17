#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack0_1(vector<pair<int, int>>& mono, int N, int W) {
    int n = N + 1;
    int w = W + 1;
    vector<vector<int>> max_value(n, vector<int>(w, 0));

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < w; j++) {
            if (mono[i-1].first > j) {
                max_value[i][j] = max_value[i-1][j];
            }
            else {
                int a = mono[i-1].second + max_value[i-1][j - mono[i-1].first];
                int b = max_value[i-1][j];
                max_value[i][j] = a > b ? a : b;
            }
        }
    }

    return max_value[N][W];
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    vector<pair<int, int>> mono;
    for (int i = 0; i < N; i++) {
        int w, v;
        scanf("%d %d", &w, &v);
        mono.push_back(make_pair(w, v));
    }
    sort(mono.begin(), mono.end());

    int ans = knapsack0_1(mono, N, K);
    printf("%d", ans);

    return 0;
}