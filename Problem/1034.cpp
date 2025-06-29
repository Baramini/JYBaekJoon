#include <iostream>
using namespace std;

bool complete = false;
int N, M, max = 0;
int check_row(int** lamp) {

}
void select_col(int** lamp, int c, int k) {
    if (!complete) {
        
    }
    return;
}

int main() {
    int k;
    cin >> N >> M;
    int** lamp = new int*[N];
    for (int i = 0; i < N; i++) lamp[i] = new int[M];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> lamp[i][j];
    cin >> k;

    select_col(lamp, 0, k);
}