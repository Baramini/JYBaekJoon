#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp1(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
bool comp2(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int N, j;
    cin >> N;
    vector<pair<int, int>> B;
    pair<int, int> k;
    for (int i = 0; i < N; i++) {
        cin >> j;
        k = {i, j};
        B.push_back(k);
    }
    stable_sort(B.begin(), B.end(), comp2);
    for (j = 0; j < N; j++) {
        B[j].second = j;
    }
    sort(B.begin(), B.end(), comp1);
    for (vector<pair<int, int>>::iterator i = B.begin(); i != B.end(); i++) {
        k = *i;
        cout << k.second << ' ';
    }
}