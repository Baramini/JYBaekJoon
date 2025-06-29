#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M, maxE, maxS = 1;
    cin >> N >> M;
    maxE = (N < M) ? N : M;

    string s;
    int **arr = new int*[N];
    for (int i = 0; i < N; i++) arr[i] = new int[M];
    for (int j = 0; j < N; j++) {
        cin >> s;
        for (int k = 0; k < M; k++) {
            arr[j][k] = (int)(s[k] - '0');
        }
    }

    for (int i = 1; i < maxE; i++) {
        for (int j = 0; j < N - i; j++) {
            if ((i + 1) * (i + 1) == maxS) break;
            for (int k = 0; k < M - i; k++) {
                if ((i + 1) * (i + 1) == maxS) break;
                int a = arr[j][k];
                int b = arr[j][k + i];
                int c = arr[j + i][k];
                int d = arr[j + i][k + i];
                if (a == b && c == d && a == c) maxS = (i + 1) * (i + 1);
            }
        }
    }
    cout << maxS;

    for (int i = 0; i < N; i++) delete[] arr[i];
    delete[] arr;
}