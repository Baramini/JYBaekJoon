#include <iostream>
using namespace std;

int main() {
    int Ax, Ay;
    int Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    
    int K = 0;
    if (Ax == 0) {
        if (Bx == 0 && Ay > By) K = 3;
        else K = 1;
    }
    else if (Ay == 0) {
        if (By == 0 && Ax > Bx) K = 3;
        else K = 1;
    }
    else K = 2;

    cout << K;
}