#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	set<string> h;
	set<string> hv;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		h.insert(s);
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (h.count(s)) hv.insert(s);
	}
	printf("%d\n", hv.size());
	for (set<string>::iterator i = hv.begin(); i != hv.end(); i++) {
		cout << *i << '\n';
	}
}