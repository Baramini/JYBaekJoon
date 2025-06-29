#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	set<string> S;
	for (int i = 0; i < str.size(); i++) {
		for (int k = 1; k <= str.size(); k++) {
			string s = str.substr(i, k);
			S.insert(s);
		}
	}
	printf("%d", S.size());
}