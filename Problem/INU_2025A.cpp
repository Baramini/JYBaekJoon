#include <iostream>
#include <vector>

using namespace std;

struct student {
    int income;
    float grade;
    int score;
};

int main() {
    int arr[11];
    for (int i = 0; i < 11; i++) cin >> arr[i];

    int N;
    scanf("%d", &N);

    student* list = new student[N];
    for (int i = 0; i < N; i++) {
        int j;
        float f;
        int k;

        cin >> j >> f >> k;
        list[i].income = j;
        list[i].grade = f;
        list[i].score = k;
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (list[i].grade >= 2.00f) {
            if (list[i].score >= 17) {
                answer += arr[list[i].income];
            }
        }
    }

    printf("%d", answer);

    delete(list);

    return 0;
}