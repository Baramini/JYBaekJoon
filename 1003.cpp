#include <iostream>
using namespace std;

int a, b;

void fibonacci(int n) {
    if (n == 0) {
        a++;
        return;
    }
    else if (n == 1) {
        b++;
        return;
    }
    int arr[3] = { 0, 1, 1 };
    for (int i = 2; i < n; i++) {
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[0] + arr[1];
    }
    a = arr[1];
    b = arr[2];
}

int main() {
    int T, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        a = 0;
        b = 0;
        cin >> n;
        fibonacci(n);
        cout << a << ' ' << b << endl;
    }
}