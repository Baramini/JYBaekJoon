#include <iostream>
#include <vector>

using namespace std;

int k;
int combination[6];
vector<int> lotto;

void printCombination() {
    cout << combination[0] << ' ' << combination[1] << ' '
    << combination[2] << ' ' << combination[3] << ' '
    << combination[4] << ' ' << combination[5] << '\n';
}

void printAllLotto(int fIndex, int bIndex, int fLotto, int bLotto) {
    if (bLotto == k || fLotto == (k-1)) return;
    combination[bIndex] = lotto[bLotto];
    printCombination();
    printAllLotto(fIndex, bIndex, fLotto, bLotto + 1);
    combination[fIndex] = lotto[fLotto + 1];
    printAllLotto(fIndex, bIndex, fLotto + 1, bLotto + 1);
}

int main() {
    cin >> k;
    while (k != 0) {
        lotto.clear();
        for (int i = 0; i < k; i++) {
            int n;
            cin >> n;
            lotto.push_back(n);
        }

        for (int i = 0; i < 6; i++) combination[i] = lotto[i];

        printAllLotto(4, 5, 4, 5);
        cin >> k;
    }

    return 0;
}