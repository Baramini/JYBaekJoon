#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int L, n, ans;
    cin >> L;
    vector<int> v;
    for (int i = 0; i < L; i++) {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    cin >> n;

    vector<int>::iterator i = v.begin();
    if (L == 1) ans = 0;
    else if (*i > n) {
        
    }
    else {
        for (i = v.begin(); i != (v.end() - 2); i++) {
            if ((*i == n) || ((*i < n && *(i + 1) > n))) break;
        }
        if (*i == n) ans = 0;
        else if (*(i + 1) - *i < 3) ans = 0;
        else {
            int a, b;
            a = *i++; b = *i - 1;
            ans = 0;
            for (int j = a + 1; j <= n; j++) {
                ans += (b - j);
                if (n - j > 1) ans -= (n - j - 1);
            }
        }
    }
    
    cout << ans;
}