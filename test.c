#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* link;
} node;

int main() {
    node A;
    node B;
    A.data = 1;
    B.data = 5;
    A.link = &B;
    B.link = NULL;

    printf("%d %d %p", A.data, A.link->data, A.link->link);
}