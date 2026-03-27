#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct abc {
    int a;
    int b;
    int c;

    bool operator<(const abc& other) const {
        if (a != other.a) {
            return a < other.a;
        }
        else if (b != other.b) {
            return b < other.b;
        }
        return c < other.c;
    }
};

map<abc, int> dp_map;

void set_dp_map(abc key, int value) {
    dp_map[key] = value;
}

int w(int a, int b, int c) {
    abc value = {a, b, c};
    if (dp_map.find(value) != dp_map.end()) {
        return dp_map[value];
    }

    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    if (a < b && b < c) {
        int i = w(a, b, c-1);   set_dp_map({a, b, c-1}, i);
        int j = w(a, b-1, c-1); set_dp_map({a, b-1, c-1}, j);
        int k = w(a, b-1, c);   set_dp_map({a, b-1, c}, k);

        return (i + j - k);
    }

    int i = w(a-1, b, c);       set_dp_map({a-1, b, c}, i);
    int j = w(a-1, b-1, c);     set_dp_map({a-1, b-1, c}, j);
    int k = w(a-1, b, c-1);     set_dp_map({a-1, b, c-1}, k);
    int l = w(a-1, b-1, c-1);   set_dp_map({a-1, b-1, c-1}, l);
    return (i + j + k - l);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    bool exited = false;

    while (!exited) {
        int ans = w(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << endl;

        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) exited = true;
    }
}