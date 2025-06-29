#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	set<int> A;
	set<int> B;
	for (int i = 0; i < N; i++) {
		int a; scanf("%d", &a);
		A.insert(a);
	}
	for (int i = 0; i < M; i++) {
		int b; scanf("%d", &b);
		B.insert(b);
	}

	int ans, cnt = 0;
	for (set<int>::iterator i = A.begin(); i != A.end(); i++) {
		if (B.count(*i)) cnt++;
	}
	ans = A.size() - cnt;
	cnt = 0;
	for (set<int>::iterator i = B.begin(); i != B.end(); i++) {
		if (A.count(*i)) cnt++;
	}
	ans += B.size() - cnt;
	printf("%d", ans);
}