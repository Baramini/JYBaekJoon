#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int N) {
    if (N < 2) return false;
    for (int i = 2; i * i <= N; i++) {
    	if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        vector<int> primes;
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            if (isPrime(j)) primes.push_back(j);
        }
        if (primes.empty()) {
            
        }
    }
    
    return 0;
}