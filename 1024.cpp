#include <iostream>
using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    for (int i = L; i < 101; i++) {
        int m = N / i;
        if (i % 2 == 0) {
            int s = 0;
            if (m - i / 2 + 1 < 0) continue;
            for (int j = m - i / 2 + 1; j < m + i / 2 + 1; j++) s += j;
            if (s == N) {
                for (int j = m - i / 2 + 1; j < m + i / 2 + 1; j++) cout << j << ' ';
                return 0;
            }
        }
        else {
            if (N % i == 0) {
                if (m - i / 2 < 0) continue;
                for (int j = m - i / 2; j < m + i / 2 + 1; j++) cout << j << ' ';
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}