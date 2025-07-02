#include <iostream>
#include <vector>

using namespace std;

vector<char> answer;

void push_stack(vector<int>* stack, int item) {
    stack->push_back(item);
    answer.push_back('+');
}

int pop_stack(vector<int>* stack) {
    int k = *(stack->end());
    stack->pop_back();
    answer.push_back('-');
    return k;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        nums.push_back(k);
    }

    vector<int> stack;
    int input_num = 1;

    int k = 0;
    while (k != n) {
        if (stack.empty()) {
            push_stack(&stack, input_num++);
        }
        else {
            int top = *(stack.end() - 1);
            int target = nums[k];

            if (top < target) push_stack(&stack, input_num++);
            else if (top == target) {
                pop_stack(&stack);
                k++;
            }
            else {
                printf("NO");
                return 0;
            }
        }
    }

    for (vector<char>::iterator c = answer.begin(); c != answer.end(); c++) {
        printf("%c\n", *c);
    }
}