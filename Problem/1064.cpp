#include <iostream>
#include <cmath>
#include <iomanip>

struct point {
    int x;
    int y;
};

bool is_not_established(point& A, point& B, point& C) {
    double dx_AB = B.x - A.x;
    double dy_AB = B.y - A.y;
    double dx_BC = C.x - B.x;
    double dy_BC = C.y - B.y;

    if (dx_AB == 0 && dx_BC == 0) return true;
    if (dy_AB == 0 && dy_BC == 0) return true;

    if (dx_AB == 0 || dx_BC == 0) return false;
    if (dy_AB == 0 || dy_BC == 0) return false;

    if (dy_AB / dx_AB == dy_BC / dx_BC) return true;
    return false;
}

double search_round(point& A, point& B, point& C) {
    double AB = std::hypot((double)(B.x - A.x), (double)(B.y - A.y));
    double BC = std::hypot((double)(C.x - B.x), (double)(C.y - B.y));
    double CA = std::hypot((double)(A.x - C.x), (double)(A.y - C.y));

    double max = AB*2 + BC*2;
    double min = max;

    double temp = BC*2 + CA*2;
    if (temp > max) max = temp;
    if (temp < min) min = temp;

    temp = CA*2 + AB*2;
    if (temp > max) max = temp;
    if (temp < min) min = temp;

    return max - min;
}

int main() {
    point A, B, C;
    std::cin >> A.x >> A.y;
    std::cin >> B.x >> B.y;
    std::cin >> C.x >> C.y;

    if (is_not_established(A, B, C)) {
        std::cout << "-1.0";
        return 0;
    }

    double answer = search_round(A, B, C);
    double int_part;

    if (std::modf(answer, &int_part) != 0.0) std::cout << std::setprecision(20) << answer;
    else std::cout << int_part << ".0";

    return 0;
}