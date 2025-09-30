#include <iostream>
#include <queue>

using namespace std;

int M, N;

int BFS(int** box, queue<pair<int, int>>& riped, int count_all) {
    int day = -1;
    int count = 0;

    while(!riped.empty()) {
        day++;
        int size = riped.size();
        count += size;

        for (int i = 0; i < size; i++) {
            pair<int, int> rc = riped.front();
            riped.pop();

            int r = rc.first;
            int c = rc.second;

            if (r == 0) {
                if (c == 0) {
                    if (box[0][1] == 0) {
                        box[0][1] = 1;
                        riped.push(pair(0, 1));
                    }
                    if (box[1][0] == 0) {
                        box[1][0] = 1;
                        riped.push(pair(1, 0));
                    }
                }
                else if (c == M - 1) {
                    if (box[0][M - 2] == 0) {
                        box[0][M - 2] = 1;
                        riped.push(pair(0, M - 2));
                    }
                    if (box[1][M - 1] == 0) {
                        box[1][M - 1] = 1;
                        riped.push(pair(1, M - 1));
                    }
                }
                else {
                    if (box[0][c - 1] == 0) {
                        box[0][c - 1] = 1;
                        riped.push(pair(0, c - 1));
                    }
                    if (box[0][c + 1] == 0) {
                        box[0][c + 1] = 1;
                        riped.push(pair(0, c + 1));
                    }
                    if (box[1][c] == 0) {
                        box[1][c] = 1;
                        riped.push(pair(1, c));
                    }
                }
            }
            else if (r == N - 1) {
                if (c == 0) {
                    if (box[N - 1][1] == 0) {
                        box[N - 1][1] = 1;
                        riped.push(pair(N - 1, 1));
                    }
                    if (box[N - 2][0] == 0) {
                        box[N - 2][0] = 1;
                        riped.push(pair(N - 2, 0));
                    }
                }
                else if (c == M - 1) {
                    if (box[N - 1][M - 2] == 0) {
                        box[N - 1][M - 2] = 1;
                        riped.push(pair(N - 1, M - 2));
                    }
                    if (box[N - 2][M - 1] == 0) {
                        box[N - 2][M - 1] = 1;
                        riped.push(pair(N - 2, M - 1));
                    }
                }
                else {
                    if (box[N - 1][c - 1] == 0) {
                        box[N - 1][c - 1] = 1;
                        riped.push(pair(N - 1, c - 1));
                    }
                    if (box[N - 1][c + 1] == 0) {
                        box[N - 1][c + 1] = 1;
                        riped.push(pair(N - 1, c + 1));
                    }
                    if (box[N - 2][c] == 0) {
                        box[N - 2][c] = 1;
                        riped.push(pair(N - 2, c));
                    }
                }
            }
            else {
                if (c == 0) {
                    if (box[r - 1][0] == 0) {
                        box[r - 1][0] = 1;
                        riped.push(pair(r - 1, 0));
                    }
                    if (box[r + 1][0] == 0) {
                        box[r + 1][0] = 1;
                        riped.push(pair(r + 1, 0));
                    }
                    if (box[r][1] == 0) {
                        box[r][1] = 1;
                        riped.push(pair(r, 1));
                    }
                }
                else if (c == M - 1) {
                    if (box[r - 1][M - 1] == 0) {
                        box[r - 1][M - 1] = 1;
                        riped.push(pair(r - 1, M - 1));
                    }
                    if (box[r + 1][M - 1] == 0) {
                        box[r + 1][M - 1] = 1;
                        riped.push(pair(r + 1, M - 1));
                    }
                    if (box[r][M - 2] == 0) {
                        box[r][M - 2] = 1;
                        riped.push(pair(r,  M - 2));
                    }
                }
                else {
                    if (box[r - 1][c] == 0) {
                        box[r - 1][c] = 1;
                        riped.push(pair(r - 1, c));
                    }
                    if (box[r + 1][c] == 0) {
                        box[r + 1][c] = 1;
                        riped.push(pair(r + 1, c));
                    }
                    if (box[r][c - 1] == 0) {
                        box[r][c - 1] = 1;
                        riped.push(pair(r, c - 1));
                    }
                    if (box[r][c + 1] == 0) {
                        box[r][c + 1] = 1;
                        riped.push(pair(r, c + 1));
                    }
                }
            }
        }
    }
    
    if (count_all != count) day = -1;

    return day;
}

int main() {
    scanf("%d", &M);
    scanf("%d", &N);
    int count = M * N;

    int** box = new int*[N];
    for (int i = 0; i < N; i++) box[i] = new int[M]();

    queue<pair<int, int>> riped;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int k;
            scanf("%d", &k);
            box[i][j] = k;
            if (k == 1) riped.push(pair(i, j));
            else if (k == -1) count--;
        }
    }

    int day = BFS(box, riped, count);
    printf("%d", day);

    for (int i = 0; i < N; i++) delete(box[i]);
    delete(box);

    return 0;
}