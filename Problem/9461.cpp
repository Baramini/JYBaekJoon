#include <iostream>
#include <vector>

using namespace std;

long long dp(vector<long long>& dp_arr, int k) {
    if (k < 5 || dp_arr[k] != 0) return dp_arr[k];

    dp_arr[k] = dp(dp_arr, k - 5) + dp(dp_arr, k - 1);

    return dp_arr[k];
}

int main() {
    vector<long long> dp_arr(100, 0);
    dp_arr[0] = 1;
    dp_arr[1] = 1;
    dp_arr[2] = 1;
    dp_arr[3] = 2;
    dp_arr[4] = 2;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        cout << dp(dp_arr, k - 1) << endl;
    }
}