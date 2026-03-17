#include <iostream>
#include <vector>

int max = -1000000000;
int min = 1000000000;
std::vector<int> cal_buffer;

void searching(std::vector<int>& v, std::vector<int>& oper, int index) {
    if (index == v.size() - 1) {
        int result = *(cal_buffer.end() - 1);
        max = result > max ? result : max;
        min = result < min ? result : min;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (oper[i] > 0) {
            oper[i]--;
            switch (i) {
                case 0:
                    cal_buffer[index + 1] = cal_buffer[index] + v[index + 1];
                    searching(v, oper, index + 1);
                    break;
                case 1:
                    cal_buffer[index + 1] = cal_buffer[index] - v[index + 1];
                    searching(v, oper, index + 1);
                    break;
                case 2:
                    cal_buffer[index + 1] = cal_buffer[index] * v[index + 1];
                    searching(v, oper, index + 1);
                    break;
                case 3:
                    cal_buffer[index + 1] = cal_buffer[index] / v[index + 1];
                    searching(v, oper, index + 1);
                    break;
            }
            oper[i]++;
        }
    }
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> v;
    for (int i = 0; i < N; i++) 
    {
        int k;
        std::cin >> k;
        v.push_back(k);
    }
    cal_buffer = std::vector<int>(N);
    cal_buffer[0] = v[0];

    std::vector<int> oper;
    for (int i = 0; i < 4; i++) 
    {
        int k;
        std::cin >> k;
        oper.push_back(k);
    }

    searching(v, oper, 0);

    std::cout << max << '\n' << min;

    return 0;
}