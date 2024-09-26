#include <iostream>
using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
        if (arr[i] != i) {
            bool check = true;
            for (int j = 0; (j <= i + k) && check; j++) {
                if (arr[j] == i && arr[i] == j) check = false;
            }
            if (check) {
                cout << "No";
                delete[] arr;
                return 0;
            }
        }
    }
    for (int i = N - k + 1; i < N; i++) {
        if (arr[i] != i) {
            bool check = true;
            for (int j = i - k; (j <= N - 1) && check; j++) {
                if (arr[j] == i && arr[i] == j) check = false;
            }
            if (check) {
                cout << "No";
                delete[] arr;
                return 0;
            }
        }
    }
    for (int i = k; i <= N - k; i++) {
        if (arr[i] != i) {
            bool check = true;
            for (int j = i - k; (j < i) && check; j++) {
                if (arr[j] == i && arr[i] == j) check = false;
            }
            for (int j = i + 1; (j <= i + k) && check; j++) {
                if (arr[j] == i && arr[i] == j) check = false;
            }
            if (check) {
                cout << "No";
                delete[] arr;
                return 0;
            }
        }
    }
    cout << "Yes";
    delete[] arr;
}