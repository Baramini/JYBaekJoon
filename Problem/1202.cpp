#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<pair<int, int>> Gem;
typedef vector<int> Bag;

long long max_value(Gem& gems, Bag& bags) {
    long long max_val = 0;

    priority_queue<int> selected_gems;
    int j = 0;
    for (int i = 0; i < bags.size(); i++) {
        while (j < gems.size() && bags[i] >= gems[j].first) {
            selected_gems.push(gems[j++].second);
        }
        if (!selected_gems.empty()) {
            max_val += selected_gems.top();
            selected_gems.pop();
        }
    }

    return max_val;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Gem gems;
    Bag bags;

    for (int i = 0; i < N; i++) {
        int j, k;
        scanf("%d %d", &j, &k);
        gems.push_back(pair(j, k));
    }
    sort(gems.begin(), gems.end());
    for (int i = 0; i < K; i++) {
        int j;
        scanf("%d", &j);
        bags.push_back(j);
    }
    sort(bags.begin(), bags.end());

    long long ans = max_value(gems, bags);
    printf("%lld", ans);

    return 0;
}