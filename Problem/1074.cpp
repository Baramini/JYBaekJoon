#include <iostream>
#include <math.h>

using namespace std;

int r, c;
int part[4];

void dividePart(int startCell, int quaterCellSize) {
    part[0] = startCell;
    part[1] = part[0] + quaterCellSize;
    part[2] = part[1] + quaterCellSize;
    part[3] = part[2] + quaterCellSize;
}

void zFunction(int qCS, int rCenter, int cCenter) {
    if (qCS == 1) {
        if (r != rCenter) {
            if (c != cCenter) {  // 0, 0
                printf("%d", part[0]);
            }
            else {              // 0, 1
                printf("%d", part[1]);
            }
        }
        else {
            if (c != cCenter) {  // 1, 0
                printf("%d", part[2]);
            }
            else {              // 1, 1
                printf("%d", part[3]);
            }
        }
        return;
    }
    int qES = (int)(sqrt(qCS)) / 2;
    if (r < rCenter) {
        if (c < cCenter) {  // 0, 0
            dividePart(part[0], qCS/4);
            zFunction(qCS/4, rCenter - qES, cCenter - qES);
        }
        else {              // 0, 1
            dividePart(part[1], qCS/4);
            zFunction(qCS/4, rCenter - qES, cCenter + qES);
        }
    }
    else {
        if (c < cCenter) {  // 1, 0
            dividePart(part[2], qCS/4);
            zFunction(qCS/4, rCenter + qES, cCenter - qES);
        }
        else {              // 1, 1
            dividePart(part[3], qCS/4);
            zFunction(qCS/4, rCenter + qES, cCenter + qES);
        }
    }
}

int main() {
    int N;
    cin >> N >> r >> c;

    int edgeSize = (int)pow(2.0, (double)N);
    int quaterCellSize = (int)(edgeSize * edgeSize / 4);
    dividePart(0, quaterCellSize);

    zFunction(quaterCellSize, edgeSize/2, edgeSize/2);

    return 0;
}