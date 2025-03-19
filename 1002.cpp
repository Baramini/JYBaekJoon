#include <iostream>
#include <cmath>
using namespace std;

int turret() {
	int x1, y1, x2, y2;
	double r1, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	if (x1 == x2 && y1 == y2 && r1 == r2) return -1;
	
	double d;
	d = sqrt(pow(double(x2 - x1), 2.0) + pow(double(y2 - y1), 2.0));
	if (abs(r1 - r2) > d || d > (r1 + r2)) return 0;
	if (abs(r1 - r2) == d || d == (r1 + r2)) return 1;
	return 2;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << turret() << endl;
	}
	system("pause");
}