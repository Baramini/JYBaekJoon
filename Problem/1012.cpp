#include <iostream>
using namespace std;

void check(int** arr, int r, int c, int n, int m) {
    if ((c - 1 >= 0) && arr[r][c - 1] != 0) {
        arr[r][c] = 0;
        check(arr, r, (c - 1), n, m);
    }
    if ((r - 1 >= 0) && arr[r - 1][c] != 0) {
        arr[r][c] = 0;
        check(arr, (r - 1), c, n, m);
    }
    if ((c + 1 < m) && arr[r][c + 1] != 0) check(arr, r, (c + 1), n, m);
    if ((r + 1 < n) && arr[r + 1][c] != 0) check(arr, (r + 1), c, n, m);    
    arr[r][c] = 0;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int M, N, K, cnt = 0;
        cin >> M >> N >> K;
        int** arr = new int*[N];
        for (int j = 0; j < N; j++) arr[j] = new int[M]();
        for (int j = 0; j < K; j++) {
            int r, c;
            cin >> c >> r;
            arr[r][c]++;
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[j][k] != 0) {
                    check(arr, j, k, N, M);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
        for (int j = 0; j < N; j++) {
            delete[] arr[j];
        }
        delete[] arr;
    }
 }