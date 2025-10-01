#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int answer = 0;
    int plus = 1;
    answer += plus;

    char pre = str[0];
    for (int i = 1; i < str.size(); i++) {
        if (pre < str[i]) plus++;
        else plus = 1;
        
        pre = str[i];
        answer += plus;
    }

    printf("%d", answer);
    
    return 0;
}