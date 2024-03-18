#include <iostream>
using namespace std;

int main() {
    int N, a, b, cnt = 1;
    cin >> N >> a >> b;
    a--;
    b--;
    while (a / 2 != b / 2) {
        if (N % 2 == 1) {
            if (a == N) a++;
            if (b == N) b++;
            N++;
        }
        a /= 2;
        b /= 2;
        N /= 2;
        cnt++;
    }
    cout << cnt;
}