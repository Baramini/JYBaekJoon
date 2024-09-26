#include <iostream>
using namespace std;

int main() {
    int x = -1, y = -1;
    int check[4][10] = {0, };
    char arr[4][10];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];
        }
    }
    char shot[9];
    for (int i = 0; i < 9; i++) cin >> shot[i];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (shot[0] == arr[i][j]) {
                x = i;
                y = j;
                check[x][y]++;
                break;
            }
        }
        if (x + y != -2) break;
    }

    for (int i = x - 2; i <= x + 2; i++) {
        if (i < 0 || i > 3) continue;
        for (int j = y - 2; j <= y + 2; j++) {
            if (j < 0 || j > 10) continue;
            for (int k = 1; k < 9; k++) {
                if (shot[k] == arr[i][j]) {
                    check[i][j]++;
                    break;
                }
            }
        }
    }

    x = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (check[i][j] == 1) x++;
            if (x == 5) {
                cout << arr[i][j];
                break;
            }
        }
        if (x == 5) break;
    }
}