#include <iostream>
#include <string.h>
using namespace std;

void check(int** arr, int x, int y) {
    
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int M, N, K, cnt = 0;
        cin >> M >> N >> K;
        int** arr = new int*[M];
        for (int j = 0; j < M; j++) {
            arr[j] = new int[N];
            memset(arr[j], 0, sizeof(int) * N);
        }
        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            arr[x][y]++;
        }
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[k][j] != 0) check(arr, k, j);
                cnt++;
            }
        }
        for (int j = 0; j < M; j++) {
            delete[] arr[j];
        }
        delete[] arr;
    }
 }