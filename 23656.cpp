#include <iostream>

using namespace std;

int main() {
    int a = 1000000000;
    int b = 1;
    int k = (a + b)/2;

    int x;
    int cnt = 0;
    while (cin >> x) {
        cnt++;
        if (x > k) {
            cout << '<' << '\n';
            a = x;
        }
        else if (x < k) {
            cout << '>' << '\n';
            b = x;
        }
        else {
            if (cnt >= 30) {
                cout << '=' << '\n';
                break;
            }
            else {
                cout << '>' << '\n';
                b = x;
            }
        }
        k = (a + b)/2;
    }

    fflush(stdout);
}