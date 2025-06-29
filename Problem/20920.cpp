#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;

bool cmp(string a, string b) {
    if (m[a] == m[b]) {
        if (a.size() > b.size()) return true;
        else if (a.size() < b.size()) return false;
        else {
            if (a.compare(b) < 0) return true;
            else return false;
        }
    }
    else if (m[a] > m[b]) return true;
    else return false;
}

int main() {
    int N, M;
    cin >> N >> M;
    char str[11];
    string s;
    vector<string> v;
    
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        s = str;
        if (s.size() >= M) {
            if (m.find(s) == m.end()) {
                m.insert({s, 1});
                v.push_back(s);
            }
            else {
                m[s]++;
            }
        }
    }

    sort(v.begin(), v.end(), cmp);
    for (vector<string>::iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << '\n';
    }
}