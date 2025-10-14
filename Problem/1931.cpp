#include <iostream>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

struct Comp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    }
};

int max_meetings(int n, priority_queue<pair<int, int>, vector<pair<int, int>>, Comp>& meetings) {
    deque<pair<int, int>> time_table;

    time_table.push_back(meetings.top());
    meetings.pop();

    while (!meetings.empty()) {
        auto new_meet = meetings.top();
        meetings.pop();

        auto reserved_last = time_table.back();
        if (new_meet.first >= reserved_last.second) time_table.push_back(new_meet);
    }

    return time_table.size();
}

int main() {
    int n;
    scanf("%d", &n);

    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> meetings;

    for (int i = 0; i < n; i++) {
        int j, k;
        scanf("%d %d", &j, &k);
        meetings.push(pair(j, k));
    }

    int ans = max_meetings(n, meetings);

    printf("%d", ans);

    return 0;
}