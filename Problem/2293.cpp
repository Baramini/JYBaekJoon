#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int combination_coins(vector<int>& coins, int N, int K) {
    vector<vector<int>> combination(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            
        }
    }

    return combination[N][K];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int j;
        scanf("%d", &j);
        coins.push_back(j);
    }
    sort(coins.begin(), coins.end());

    int ans = combination_coins(coins, n, k);
    printf("%d", ans);
}