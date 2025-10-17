#include <iostream>
#include <vector>

using namespace std;

int min_mulpitle_matrices(vector<pair<int, int>>& matrices) {
    int n = matrices.size();
    vector<vector<int>> min(n, vector<int>(n, 2147383647));

    for (int i = 0; i < n; i++) min[i][i] = 0;
    
    for (int L = 0; L < n; L++) {
        for (int i = 0; i < n - L; i++) {
            int j = i + L;
            for (int k = i; k <= j - 1; k++) {
                int temp = min[i][k] + min[k+1][j] + matrices[i].first * matrices[k].second * matrices[j].second;
                if (min[i][j] > temp) {
                    min[i][j] = temp;
                }
            }
        }
    }

    return min[0][n-1];
}

int main() {
    int N;
    scanf("%d", &N);

    vector<pair<int, int>> matrices;
    for (int i = 0; i < N; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        matrices.push_back(make_pair(r, c));
    }

    int ans = min_mulpitle_matrices(matrices);
    printf("%d", ans);

    return 0;
}