#include <iostream>
using namespace std;

int main() {
    int N, M, MinP = 1001, min = 1001, ans;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (MinP > a) MinP = a;
        if (min > b) min = b;
    }
    if (MinP > min * 6) ans = N * min;
    else {
        ans = MinP * (N / 6);
        N %= 6;
        if (MinP < min * N) ans += MinP;
        else ans += (min * N);
    }
    cout << ans;
}