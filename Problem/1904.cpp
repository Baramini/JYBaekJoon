#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> dp_arr(N + 1, 0);
    if (N == 1) {
        cout << 1;
        return 0;
    }

    dp_arr[1] = 1;
    dp_arr[2] = 2;

    for (int i = 3; i < N + 1; i++) {
        dp_arr[i] = (dp_arr[i - 1] + dp_arr[i - 2]) % 15746;
    }

    cout << dp_arr[N];
}