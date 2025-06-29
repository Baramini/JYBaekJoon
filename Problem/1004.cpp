#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x1, y1, x2, y2, n, cx, cy, r, cnt = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        for (int j = 0; j < n; j++) {
            cin >> cx >> cy >> r;
            if (((pow((x1 - cx), 2.0) + pow((y1 - cy), 2.0)) < r * r) && ((pow((x2 - cx), 2.0) + pow((y2 - cy), 2.0)) > r * r)) cnt++;
            if (((pow((x1 - cx), 2.0) + pow((y1 - cy), 2.0)) > r * r) && ((pow((x2 - cx), 2.0) + pow((y2 - cy), 2.0)) < r * r)) cnt++;
        }
        cout << cnt << endl;
    }
}