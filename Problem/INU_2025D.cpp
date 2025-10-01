#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> arr;
    for (int i = 0; i < N; i++) arr.push_back(i + 1);

    if (N % 2 == 1) {
        printf("%d ", arr[N / 2]);
    }
    for (int i = N / 2 - 1; i >= 0; i--) {
        printf("%d %d ", arr[i], arr[N - 1 - i]);
    }
    
    return 0;
}