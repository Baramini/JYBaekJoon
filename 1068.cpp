#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int* arr;
    arr = new int[N];
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        k += 2;
        arr[i] = k;
    }
    
    
}