#include <iostream>
#include <vector>
using namespace std;

int main() {
    int L, n, ans = 0;
    int low = 1001, A;
    int high = -1001, B;

    cin >> L;
    vector<int> v;
    for (int i = 0; i < L; i++) {
        cin >> n;
        v.push_back(n);
    }
    cin >> n;

    for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        int j = n - *i;
        if (j > 0) {
            if (low > j) low = j;
        }
        else {
            if (high < j) high = j;
        }
    }
    if (low == 1001) A = 0;
    else A = n - low;
    B = n + (-high);

    ans = (n - A) * (B - n);
    ans = (ans > 0) ? ans - 1 : ans; 
    cout << ans;
}