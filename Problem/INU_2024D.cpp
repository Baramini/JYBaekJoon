#include <iostream>
using namespace std;

int main() {
    int x, y, z;
    int N, M;
    cin >> N >> M;
    int A, Amin = 1, Amax = N;
    int B, Bmin = 1, Bmax = N;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        switch (z) {
            case 1: {
                if (Amax > x - 1) Amax = x - 1;
                Bmin = y;
                Bmax = y;
                break;
            }
            case 2: {
                if (Amax > x - 1) Amax = x - 1;
                if (Bmin < y + 1) Bmin = y + 1;
                break;
            }
            case 3: {
                Amin = x;
                Amax = x;
                if (Bmin < y + 1) Bmin = y + 1;
                break;
            }
            case 4: {
                if (Amin < x + 1) Amin = x + 1;
                if (Bmin < y + 1) Bmin = y + 1;
                break;
            }
            case 5: {
                if (Amin < x + 1) Amin = x + 1;
                Bmin = y;
                Bmax = y;
                break;
            }
            case 6: {
                if (Amin < x + 1) Amin = x + 1;
                if (Bmax > y - 1) Bmax = y - 1;
                break;
            }
            case 7: {
                Amin = x;
                Amax = x;
                if (Bmax > y - 1) Bmax = y - 1;
                break;
            }
            default: {
                if (Amax > x - 1) Amax = x - 1;
                if (Bmax > y - 1) Bmax = y - 1;
                break;
            }
        }
    }

    A = Amin;
    B = Bmin;
    cout << A << ' ' << B;
}