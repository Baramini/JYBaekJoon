#include <iostream>
using namespace std;

int main() {
    int N, M, sqa = 1, min, edge = 2;
    cin >> N >> M;
    int** rec = new int*[N];
    for (int i = 0; i < N; i++) rec[i] = new int[M];
    min = (N > M) ? M : N;
    while (min >= edge) {
        for (int i = 0; i < N - edge; i++) {
            for (int j = 0; j < M - edge; j++) {
                if ()
            }
        }
    }
}