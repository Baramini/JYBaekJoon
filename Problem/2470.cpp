#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void search_two_value(vector<int>& data_vec, int& X, int& Y) {
    int ans = 2100000000, sum;
    int A, B;

    vector<int>::iterator i = data_vec.begin(), j = data_vec.end()-1;

    while (*i != 0 && *j != 0) {
        A = *i;
        B = *j;
        sum = A + B;
        if (abs(ans - 0) > abs(sum - 0)) {
            ans = sum;
            X = A;
            Y = B;
        }

        if (sum > 0) j--;
        else if (sum < 0) i++;
        else return; // 합이 0으로 더 이상 진행 필요X
    }

    int index = ((*i == 0) ? i : j) - data_vec.begin();

    if (index > 1) {
        A = data_vec[index - 2];
        B = data_vec[index - 1];
        sum = A + B;
        if (abs(ans - 0) > abs(sum - 0)) {
            ans = sum;
            X = A;
            Y = B;
        }
    }
    if (index < data_vec.size()-2) {
        A = data_vec[index + 1];
        B = data_vec[index + 2];
        sum = A + B;
        if (abs(ans - 0) > abs(sum - 0)) {
            ans = sum;
            X = A;
            Y = B;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> data_vec;
    data_vec.push_back(0);
    for (int i = 0; i < N; i++) {
        int item;
        scanf("%d", &item);
        data_vec.push_back(item);
    }
    sort(data_vec.begin(), data_vec.end());

    int X, Y;
    search_two_value(data_vec, X, Y);

    printf("%d %d", X, Y);
}