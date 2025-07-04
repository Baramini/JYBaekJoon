#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<int>::iterator list_find(list<int>& List, int item) {
    list<int>::iterator x;
    for (x = List.begin(); x != List.end(); x++) {
        if (*x == item) break;
    }
    return x;
}
void insert_front(list<int>& List, int X, int Y) {
    list<int>::iterator from = list_find(List, X);
    list<int>::iterator to = list_find(List, Y);
    List.splice(to, List, from);
}
void insert_back(list<int>& List, int X, int Y) {
    list<int>::iterator from = list_find(List, X);
    list<int>::iterator to = list_find(List, Y);
    List.splice(++to, List, from);
}

int main() {
    int N, M;
    cin >> N >> M;

    list<int> List;
    for (int i = 1; i <= N; i++) List.push_back(i);

    for (int i = 0; i < M; i++) {
        char AB;
        int X, Y;
        cin >> AB >> X >> Y;

        if (AB == 'A') insert_front(List, X, Y);
        else insert_back(List, X, Y);
    }

    return 0;
}