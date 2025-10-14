#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

map<int, set<int>> sorted_r;
vector<pair<int, int>> points_set;

int calculate_dist(int start, int end, int n) {
    if (n == 1) return 1000000000;

    int a = points_set[start].first - points_set[end].first;
    int b = points_set[start].second - points_set[end].second;
    int ans = a*a + b*b;

    if (n == 3) {
        a = points_set[start].first - points_set[start+1].first;
        b = points_set[start].second - points_set[start+1].second;
        int i = a*a + b*b;

        a = points_set[end].first - points_set[start+1].first;
        b = points_set[end].second - points_set[start+1].second;
        int j = a*a + b*b;

        if (i < ans) ans = i;
        if (j < ans) ans = j;
    }
    return ans;
}

int closest_middle(int start, int middle, int end, int dist_double) {
    int left = start, right = end;

    int center = points_set[middle].first;
    for (int i = start; i <= middle; i++) {
        int k = (int)pow(center - points_set[i].first, 2);
        if (k < dist_double) {
            left = i;
            break;
        }
    }

    center = points_set[middle+1].first;
    for (int i = end; i >= middle+1; i--) {
        int k = (int)pow(points_set[i].first - center, 2);
        if (k < dist_double) {
            right = i;
            break;
        }
    }

    map<int, set<int>> sorted_c;
    vector<pair<int, int>> points_subset;
    for (int i = left; i <= right; i++) {
        sorted_c[points_set[i].second].insert(points_set[i].first);
    }
    for (const auto& duo : sorted_c) {
        for (const auto& second : duo.second) {
            points_subset.push_back(pair(duo.first, second));
        }
    }
    
    int min = 1000000000;
    for (int i = 0; i < points_subset.size(); i++) {
        for (int j = i + 1; (j <= i + 6) && j < points_subset.size(); j++) {
            int a = (int)pow(points_subset[i].first - points_subset[j].first, 2);
            if (a > dist_double) break;
            int b = (int)pow(points_subset[i].second - points_subset[j].second, 2);
            int k = a + b;
            if (k < min) min = k;
        }
    }

    return min;
}

int closest_pair(int start, int end) {
    int n = end - start + 1;
    if (n <= 3) return calculate_dist(start, end, n);

    int middle = start + n/2;
    int l_dist = closest_pair(start, middle);
    int r_dist = closest_pair(middle + 1, end);

    int min1 = l_dist - r_dist > 0 ? r_dist : l_dist;
    int min2 = closest_middle(start, middle, end, min1);

    return min1 - min2 > 0 ? min2 : min1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int j, k;
        scanf("%d %d", &j, &k);
        sorted_r[j].insert(k);
    }

    for (const auto& duo : sorted_r) {
        for (const auto& second : duo.second) {
            points_set.push_back(pair(duo.first, second));
        }
    }
    if (points_set.size() != n) printf("0");
    else {
        int min_dist = closest_pair(0, points_set.size() - 1);
        printf("%d", min_dist);
    }

    return 0;
}