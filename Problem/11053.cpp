#include <iostream>
#include <vector>

using namespace std;

int longest = 1;

int main() {
    int N;
    cin >> N;
    
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        v.push_back(k);
    }

    for (int i = 1; i < N; i++) {
        
    }

    printf("%d", longest);

    return 0;
}