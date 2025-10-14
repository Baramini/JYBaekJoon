#include <iostream>
#include <string>

using namespace std;

int arr[64][64];

bool check(int r, int c, int size) {
    int k = arr[r][c];
    for (int i = r; i < r+size; i++) {
        for (int j = c; j < c+size; j++) {
            if (k != arr[i][j]) return false;
        }
    }
    return true;
}
void quad_tree(int r, int c, int size) {
    if (check(r, c, size)) {
        printf("%d", arr[r][c]);
        return;
    }

    printf("(");
    int offset = size/2;
    quad_tree(r, c, offset);
    quad_tree(r, c+offset, offset);
    quad_tree(r+offset, c, offset);
    quad_tree(r+offset, c+offset, offset);
    printf(")");
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            int k = (int)(s[j] - '0');
            arr[i][j] = k;
        }
    }

    quad_tree(0, 0, N);

    return 0;
}