#include <iostream>
#include <string>
#include <vector>

using namespace std;

char get_top(vector<char>* stack) {
    return *(stack->end() - 1);
}
char pop_stack(vector<char>* stack) {
    char c = *(stack->end() - 1);
    stack->pop_back();
    return c;
}

int main() {
    string infix;
    cin >> infix;

    vector<char> stack;
    vector<char> postfix;
    for (int i = 0; i < infix.size(); i++) {
        char c = infix[i];
        if (stack.empty()) {
            stack.push_back(c);
        }
        else {
            char top = get_top(&stack);
            switch (c) {
                case '(':
                    stack.push_back(c);
                    break;
                case ')':
                    while (top != '(') {
                        postfix.push_back(pop_stack(&stack));
                        top = get_top(&stack);
                    }
                    stack.pop_back();
                    break;
                case '+':
                case '-':
                    while (top != '(' && !stack.empty()) {
                        postfix.push_back(pop_stack(&stack));
                        top = get_top(&stack);
                    }
                    stack.push_back(c);
                    break;
                case '*':
                case '/':
                    while (top != '(' && top != '+' && top != '-' && !stack.empty()) {
                        postfix.push_back(pop_stack(&stack));
                        top = get_top(&stack);
                    }
                    stack.push_back(c);
                    break;
                default:
                    stack.push_back(c);
                    break;
            }
        }
    }

    while (!stack.empty()) postfix.push_back(pop_stack(&stack));

    for (vector<char>::iterator i = postfix.begin(); i != postfix.end(); i++) putchar(*i);
}