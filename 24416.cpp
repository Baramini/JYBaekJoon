#include <iostream>
using namespace std;

int a;
void rec(int n) {
	if (n == 1 || n == 2) {
		a++;
		return;
	}
	else {
		rec(n - 1);
		rec(n - 2);
	}
}

int b;
void dp(int n) {
	for (int i = 2; i < n; i++) {
		b++;
	}
}

int main() {
	a = 0; b = 0;
	int n; cin >> n;
	rec(n);
	dp(n);
	cout << a << ' ' << b;
}