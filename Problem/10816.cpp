#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

int main() {
	int N, M;
	map<int, int> m;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d", &k);
		if (m.count(k) != 0) m[k]++;
		else m.insert({ k, 1});
	}
	scanf("%d", &M);
	int* arr = new int[M];
	for (int i = 0; i < M; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < M; i++) {
		if (m.count(arr[i]) != 0) printf("%d ", m[arr[i]]);
		else printf("0 ");
	}
	delete[] arr;
}