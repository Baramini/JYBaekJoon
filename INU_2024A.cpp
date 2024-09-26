#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    int X = 1, Y = 1;
    bool XisBad = false;
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        X += A;
        Y += B;
        if (X < Y) {
            int tmp = X;
            X = Y;
            Y = tmp;
        }
        else if (X == Y) Y--;
    }
    cout << X << ' ' << Y;
}