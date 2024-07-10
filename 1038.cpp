#include <iostream>
using namespace std;

int main() {
    int N, n = 1, cur = 1, ans = -1;
    cin >> N;
    if (N > 1023) cur = 11;
    else if (N > 1022) cur = 10;
    else if (N > 1012) cur = 9;
    else if (N > 967) cur = 8;
    else if (N > 847) cur = 7;
    else if (N > 637) cur = 6;
    else if (N > 385) cur = 5;
    else if (N > 175) cur = 4;
    else if (N > 55) cur = 3;
    else if (N > 10) cur = 2;
    else cur = 1;
    
    switch (cur) {
        case 1:
            ans = N;
        case 2:
            
        case 3:

        case 4:

        case 5:

        case 6:

        case 7:

        case 8:

        case 9:

        case 10:
            cout << "9876543210";
            break;
        default:
            cout << ans;
            break;
    }
}