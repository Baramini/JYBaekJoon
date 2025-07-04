#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    string str;
    int M;
    cin >> str >> M;

    list<char> List;
    for (int i = 0; i < str.size(); i++) List.push_back(str[i]);

    list<char>::iterator cursor = List.end();
    for (int i = 0; i < M; i++) {
        char order;
        cin >> order;
        if (order == 'L') {
            if (cursor != List.begin()) cursor--;
        }
        else if (order == 'D') {
            if (cursor != List.end()) cursor++;
        }
        else if (order == 'B') {
            if (cursor != List.begin()) {
                list<char>::iterator temp = cursor;
                List.erase(--cursor);
                cursor = temp;
            }
        }
        else {
            char item;
            cin >> item;
            if (cursor == List.begin()) List.push_front(item);
            else {
                List.insert(cursor, item);
            }
        }
    }

    for (cursor = List.begin(); cursor != List.end(); cursor++) printf("%c", *cursor);
}