#include <iostream>
using namespace std;

int main() {
	int N, M, j, k, s = 0, length;
	cin >> N >> M;
	length = N;
	int* arr = new int[N]();
	for (int i = 0; i < M; i++) {
		cin >> k;
		arr[k - 1] = ++s;
	}

	j = 0;
	k = 1;
	s = 0;
	for (int i = 0; i < M; i++) {
		int l = 0;
		while (arr[j] != k) {
			if (arr[j] != 0 && arr[j] < k) {
				j = (j + 1) % N;
				continue;
			}
			else {
				l++;
				j = (j + 1) % N;
			}
		}
		if (l < length - l) s += l;
		else s += length - l;
		k++;
		length--;
	}
	cout << s;
	delete[] arr;
}