#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        bool pos = true;
        string str;
        cin >> str;
        string::iterator iter;
        iter = str.begin();
        while(iter != str.end()) {
            if (*iter == '1') {
                if (*(++iter) == '0') {
                    if (*(++iter) == '0') {
                        while (*(iter + 1) == '0') iter++;
                        if (*(++iter) == '1') {
                            if (*(iter + 1) == '1') {
                                while (*(iter + 1) == '1') iter++;
                                if (*(iter + 1) == '0' && *(iter + 2) == '1') iter++;
                                else if (iter + 1 == str.end()) break;
                            }
                            else iter++;
                        }
                        else {
                            pos = false;
                            break;
                        }
                    }
                    else {
                        pos = false;
                        break;
                    }
                }
                else {
                    pos = false;
                    break;
                }
            }
            else {
                if (*(++iter) != '1') {
                    pos = false;
                    break;
                }
                else iter++;
            }
        }
        if (pos) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}