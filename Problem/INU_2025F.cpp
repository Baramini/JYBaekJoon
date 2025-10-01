#include <iostream>
#include <string>

using namespace std;

int N, M;

void move_player(pair<int, int>& player, pair<int, int> dir, int** map) {
    int r, c;
    r = player.first + dir.first;
    c = player.second + dir.second;

    if (r >= 0 && r < N) {
        if (c >= 0 && c < N) {
            if (map[r][c] != 1) {
                player.first = r;
                player.second = c;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    int** map = new int*[N];
    for (int i = 0; i < N; i++) map[i] = new int[N];

    pair<int, int> player;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int k;
            scanf("%d", &k);
            map[i][j] = k;
            if (k == 2) player = pair(i, j);
        }
    }
    pair<int, int> w(-1, 0);
    pair<int, int> a(0, -1);
    pair<int, int> s(1, 0);
    pair<int, int> d(0, 1);

    string WASD[4];
    for (int i = 0; i < 4; i++) {
        string str;
        cin >> str;
        WASD[i] = str;
    }
    
    string inputs;
    cin >> inputs;
    switch (inputs[0]) {
        case 'W':
            if (WASD[0].compare("Down") == 0) move_player(player, w, map);
            break;
        case 'A':
            if (WASD[1].compare("Down") == 0) move_player(player, a, map);
            break;
        case 'S':
            if (WASD[2].compare("Down") == 0) move_player(player, s, map);
            break;
        case 'D':
            if (WASD[3].compare("Down") == 0) move_player(player, d, map);
            break;
    }
    char pre_input = inputs[0];

    for (int i = 1; i < M; i++) {
        if (pre_input != inputs[i]) {
            char first_event;
            char second_event;
            if (pre_input == 'W') {
                first_event = pre_input;
                second_event = inputs[i];
                if (WASD[0].compare("Up") == 0) move_player(player, w, map);
                switch (second_event) {
                    case 'A':
                        if (WASD[1].compare("Down") == 0) move_player(player, a, map);
                        break;
                    case 'S':
                        if (WASD[2].compare("Down") == 0) move_player(player, s, map);
                        break;
                    case 'D':
                        if (WASD[3].compare("Down") == 0) move_player(player, d, map);
                        break;
                }
            }
            else if (pre_input == 'A' && (inputs[i] == 'S' || inputs[i] == 'D')) {
                first_event = pre_input;
                second_event = inputs[i];
                if (WASD[1].compare("Up") == 0) move_player(player, a, map);
                switch (second_event) {
                    case 'S':
                        if (WASD[2].compare("Down") == 0) move_player(player, s, map);
                        break;
                    case 'D':
                        if (WASD[3].compare("Down") == 0) move_player(player, d, map);
                        break;
                }
            }
            else if (pre_input == 'S' && inputs[i] == 'D') {
                first_event = pre_input;
                second_event = inputs[i];
                if (WASD[2].compare("Up") == 0) move_player(player, s, map);
                if (WASD[3].compare("Down") == 0) move_player(player, d, map);
            }
            else {
                first_event = inputs[i];
                second_event = pre_input;
                switch (first_event) {
                    case 'W':
                        if (WASD[0].compare("Down") == 0) move_player(player, w, map);
                        break;
                    case 'A':
                        if (WASD[1].compare("Down") == 0) move_player(player, a, map);
                        break;
                    case 'S':
                        if (WASD[2].compare("Down") == 0) move_player(player, s, map);
                        break;
                    case 'D':
                        if (WASD[3].compare("Down") == 0) move_player(player, d, map);
                        break;
                }
                switch (second_event) {
                    case 'W':
                        if (WASD[0].compare("Up") == 0) move_player(player, w, map);
                        break;
                    case 'A':
                        if (WASD[1].compare("Up") == 0) move_player(player, a, map);
                        break;
                    case 'S':
                        if (WASD[2].compare("Up") == 0) move_player(player, s, map);
                        break;
                    case 'D':
                        if (WASD[3].compare("Up") == 0) move_player(player, d, map);
                        break;
                }
            }
        }
        else {
            switch (inputs[i]) {
                case 'W':
                    if (WASD[0].compare("Stay") == 0) move_player(player, w, map);
                    break;
                case 'A':
                    if (WASD[1].compare("Stay") == 0) move_player(player, a, map);
                    break;
                case 'S':
                    if (WASD[2].compare("Stay") == 0) move_player(player, s, map);
                    break;
                case 'D':
                    if (WASD[3].compare("Stay") == 0) move_player(player, d, map);
                    break;
            }
        }
        pre_input = inputs[i];
    }

    printf("%d %d", player.first + 1, player.second + 1);

    for (int i = 0; i < N; i++) delete(map[i]);
    delete(map);

    return 0;
}