#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	string bomb;
	cin >> str >> bomb;
	int len = str.size(), blen = bomb.size();
	char last = bomb[blen - 1];
	vector<char> ans;
	vector<char>::iterator iter;
	for (int i = 0; i < len; i++) {
		ans.push_back(str[i]);
		if (str[i] == last && ans.size() >= blen) {
			int k = 0;
			bool explode = true;
			for (iter = ans.end() - blen; iter != ans.end() - 1; iter++) {
				if (*iter != bomb[k++]) explode = false;
			}
			if (explode) for (int j = 0; j < blen; j++) ans.pop_back();
		}
	}
	if (ans.size() == 0) cout << "FRULA";
	else for (iter = ans.begin(); iter != ans.end(); iter++) cout << *iter;
}