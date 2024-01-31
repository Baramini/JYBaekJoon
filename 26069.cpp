#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

int main() {
	int N; scanf("%d", &N);
	set<string> S;
	S.insert("ChongChong");
	for (int i = 0; i < N; i++) {
		string n1, n2;
		cin >> n1 >> n2;
		if (S.count(n1)) S.insert(n2);
		else if (S.count(n2)) S.insert(n1);
	}
	printf("%d", S.size());
}