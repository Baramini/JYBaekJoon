#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, k, ans = 0;
	cin >> N;
	int* A, * B;
	A = new int[N];
	B = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> k;
		A[i] = k;
	}
	for (int i = 0; i < N; i++) {
		cin >> k;
		B[i] = k;
	}
	sort(A, A + N);
	sort(B, B + N);
	for (int i = 0; i < N; i++) {
		ans += (A[i] * B[N - 1 - i]);
	}
	cout << ans;
}