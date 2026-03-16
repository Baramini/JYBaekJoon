#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9, 0));
vector<pair<int, int>> target;
vector<vector<bool>> checker(9, vector<bool>(9, false));

int check_vertical(int r, int c) {
    int mask = 0b000000000;
    for (int i = 0; i < r; i++) {
        if (checker[i][c]) {
            int bit_check = 1 << (sudoku[i][c] - 1);
            mask = mask | bit_check;
        }
    }
    for (int i = r + 1; i < 9; i++) {
        if (checker[i][c]) {
            int bit_check = 1 << (sudoku[i][c] - 1);
            mask = mask | bit_check;
        }
    }

    return mask;
}
int check_horizontal(int r, int c) {
    int mask = 0b000000000;
    for (int i = 0; i < c; i++) {
        if (checker[r][i]) {
            int bit_check = 1 << (sudoku[r][i] - 1);
            mask = mask | bit_check;
        }
    }
    for (int i = c + 1; i < 9; i++) {
        if (checker[r][i]) {
            int bit_check = 1 << (sudoku[r][i] - 1);
            mask = mask | bit_check;
        }
    }

    return mask;
}
int check_square(int r, int c) {
    int mask = 0b000000000;
    int start_r = r / 3 * 3;
    int start_c = c / 3 * 3;
    for (int i = start_r; i < start_r + 3; i++) {
        for (int j = start_c; j < start_c + 3; j++) {
            if (checker[i][j]) {
                int bit_check = 1 << (sudoku[i][j] - 1);
                mask = mask | bit_check;
            }
        }
    }

    return mask;
}
int get_valid_mask(int r, int c) {
    return (check_vertical(r, c) | check_horizontal(r, c) | check_square(r, c));
}

void print_sudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve_sudoku(int index) {
    if (index == target.size()) {
        print_sudoku();
        exit(0);
    }
    
    pair<int, int> rc = target[index];
    int valid_mask = get_valid_mask(rc.first, rc.second);

    for (int num = 0; num < 9; num++) {
        int num_bit = 1 << num;
        if ((num_bit & valid_mask) == 0) {
            checker[rc.first][rc.second] = true;
            sudoku[rc.first][rc.second] = num + 1;
            solve_sudoku(index + 1);

            checker[rc.first][rc.second] = false;
            sudoku[rc.first][rc.second] = 0;
        }
    }
    
}

int main() {
    int input_num = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> input_num;
            sudoku[i][j] = input_num;
            if (input_num != 0) checker[i][j] = true;
            else {
                target.push_back({i, j});
            }
        }
    }

    solve_sudoku(0);

    return 0;
}