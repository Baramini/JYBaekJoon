#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string str, cmd;
	cin >> N;
	cin >> str;
	cmd = str;

	for (int i = 0; i < N - 1; i++) {
		cin >> str;
		for (int i = 0; i < cmd.size(); i++) {
			if (str[i] != cmd[i]) cmd[i] = '?';
		}
	}
	cout << cmd;
}