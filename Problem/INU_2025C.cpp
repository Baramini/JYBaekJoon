#include <iostream>

using namespace std;

bool isPrime(int N) {
    if (N < 2) return false;
    for (int i = 2; i * i <= N; i++) {
    	if (N % i == 0) return false;
    }
    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        int A = 1, B = N + 1;
        if (isPrime(B)) printf("1\n%d %d", A, B);
        else printf("0");
        printf("\n");
    }
    
    return 0;
}