#include <iostream>
using namespace std;

int main() {
	int N, F;
	cin >> N >> F;
	int k = N - (N % 100);
	for (int i = k; i < k + 100; i++) {
		if (i % F == 0) {
			k = i;
			break;
		}
	}
	cout << (k % 100) / 10 << k % 10;
}