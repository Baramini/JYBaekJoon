#include <iostream>
#include <vector>
#include <cmath>

int min = 1000000000;
void searching(std::vector<std::vector<int>>& v, std::vector<int>& startTeam, int currentIndex, int count) {
    if (min == 0) {
        std::cout << 0;
        exit(0);
    }

    if (currentIndex == v.size()) return;

    if (count < 1) {
        std::vector<int> linkTeam;
        int startScore = 0;
        int linkScore = 0;

        int startTeamIndex = 0;
        for (int i = 0; i < v.size(); i++) {
            if (startTeam[startTeamIndex] == i) startTeamIndex++;
            else linkTeam.push_back(i);
        }

        for (int i = 0; i < startTeam.size(); i++) {
            for (int j = i + 1; j < startTeam.size(); j++) {
                int A = startTeam[i];
                int B = startTeam[j];
                startScore += (v[A][B] + v[B][A]);
            }
        }
        for (int i = 0; i < linkTeam.size(); i++) {
            for (int j = i + 1; j < linkTeam.size(); j++) {
                int A = linkTeam[i];
                int B = linkTeam[j];
                linkScore += (v[A][B] + v[B][A]);
            }
        }

        int result = std::abs(startScore - linkScore);
        min = min > result ? result : min;
        return;
    }

    if (currentIndex >= v.size()) return;

    startTeam.push_back(currentIndex);
    searching(v, startTeam, currentIndex + 1, count - 1);
    startTeam.pop_back();

    searching(v, startTeam, currentIndex + 1, count);
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> v(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int k;
            std::cin >> k;
            v[i][j] = k;
        }
    }

    std::vector<int> startTeam;
    searching(v, startTeam, 0, N/2);

    std::cout << min;
}