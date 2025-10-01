#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

int matching(string f, string m) {
    int score = 0;
    for (int i = 0; i < 4; i++) {
        if (f[i] != m[i]) score++;
    }
    return score;
}

void brute_force(int n) {
    if (n > 0) brute_force(n - 1);

    for (int i = n - 1; i < N; i++) {
        
    }
}

int main() {
    scanf("%d", &N);

    // vector<string> female;
    // vector<string> male;
    // for (int i = 0; i < N; i++) {
    //     string mbti;
    //     cin >> mbti;
    //     female.push_back(mbti);
    // }
    // for (int i = 0; i < N; i++) {
    //     string mbti;
    //     cin >> mbti;
    //     male.push_back(mbti);
    // }

    
    
    return 0;
}