#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	map<string, int> ver1;
	map<int, string> ver2;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		cin.tie(nullptr);
		ver1.insert({ s, i});
		ver2.insert({ i, s});
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		cin.tie(nullptr);
		if (atoi(s.c_str())) {
			cout << ver2[atoi(s.c_str())] << '\n';
		}
		else {
			cout << ver1[s] << '\n';
		}
	}
}