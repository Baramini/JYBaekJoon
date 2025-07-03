#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N;

typedef struct{
    int r;
    int c;
} point;

typedef struct{
    int time;
    char dir;
    char padding[3];
} mover;

bool isColWall(deque<point>& snake) {
    point head = snake.front();

    if (head.r < 0 || head.r > N-1) return true;
    if (head.c < 0 || head.c > N-1) return true;

    return false;
}
bool snake_move(deque<point>& snake, point& move_vector, vector<point>& apple) {
    point head = snake.front();
    head.r += move_vector.r;
    head.c += move_vector.c;

    for (auto& i : snake) {
        if (head.r == i.r && head.c == i.c) return true;
    }

    bool isEatApple = false;
    for (vector<point>::iterator i = apple.begin(); i != apple.end(); i++) {
        if (head.r == i->r && head.c == i->c) {
            isEatApple = true;
            apple.erase(i);
            break;
        }
    }

    snake.push_front(head);
    if (!isEatApple) snake.pop_back();
    return false;
}
void snake_changedir(deque<point>& snake, point& move_vector, char dir) {
    if (dir == 'L') {
        if (move_vector.r == 1) move_vector = {0, 1};
        else if (move_vector.c == 1) move_vector = {-1, 0};
        else if (move_vector.r == -1) move_vector = {0, -1};
        else move_vector = {1, 0};
    }
    else {
        if (move_vector.r == 1) move_vector = {0, -1};
        else if (move_vector.c == -1) move_vector = {-1, 0};
        else if (move_vector.r == -1) move_vector = {0, 1};
        else move_vector = {1, 0};
    }
}

int main() {
    cin >> N;
    int K, L;

    vector<point> apple;
    cin >> K;
    for (int i = 0; i < K; i++) {
        point p;
        cin >> p.r >> p.c;
        p.r--;
        p.c--;
        apple.push_back(p);
    }

    vector<mover> controller;
    cin >> L;
    for (int i = 0; i < L; i++) {
        mover m;
        cin >> m.time >> m.dir;
        controller.push_back(m);
    }

    deque<point> snake;
    snake.push_back({0, 0});
    int seconds = 0;
    int controller_index = 0;
    point move_vector = {0, 1};
    bool isColBody = false;

    while (!isColWall(snake) && !isColBody) {
        seconds++;
        isColBody = snake_move(snake, move_vector, apple);
        if (seconds == controller[controller_index].time) {
            snake_changedir(snake, move_vector, controller[controller_index++].dir);
        }
    }

    printf("%d", seconds);
    return 0;
}