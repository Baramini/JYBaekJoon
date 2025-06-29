#include <iostream>
using namespace std;

class stack {
    int* S;
    int top;
public:
    stack(int N) {
        S = new int[N];
        top = -1;
    }
    void push(int item) { S[++top] = item; }
    int pop() {
        if (top == -1) return -1;
        return S[top--];
    }
    int peek() {
        if (top == -1) return -1;
        return S[top];
    }
    ~stack() { delete[] S; }
};

int main() {
    int N, k;
    cin >> N;
    stack A(N), B(N), C(N);
    for (int i = 0; i < N; i++) {
        cin >> k;
        A.push(k);
    }

    for (int i = 0; i < N; i++) {
        while (A.peek() >= B.peek() && B.peek() != -1) { B.pop(); }
        C.push(B.peek());
        B.push(A.pop());
    }
    for (int i = 0; i < N; i++) { cout << C.pop() << ' '; }
}