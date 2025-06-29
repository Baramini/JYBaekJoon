#include <iostream>
#include <vector>

using namespace std;

int k;
vector<int> lotto;
vector<int> combination;

void drawing(int start) {

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
        
        cin >> k;
    }

    return 0;
}