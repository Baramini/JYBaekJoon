#include <iostream>
using namespace std;

int N;
int check(int* bil, int i) {
    double min = -10000000000.0, tan;
    int cnt = 0;
    int pos = bil[i];
    for (int j = i - 1; j >= 0; j--) {
        tan = (double)(bil[j] - pos) / (double)(i - j);
        if (tan > min) {
            min = tan;
            cnt++;
        }
    }

    min = -10000000000.0;
    for (int j = i + 1; j < N; j++) {
        tan = (double)(bil[j] - pos) / (double)(j - i);
        if (tan > min) {
            min = tan;
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int k, max = 0;
    cin >> N;
    int* bil = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> k;
        bil[i] = k;
    }
    for (int i = 0; i < N; i++) {
        int cnt = check(bil, i);
        if (cnt > max) max = cnt;
    }
    cout << max;
}