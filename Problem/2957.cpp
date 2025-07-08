#include <iostream>
#include <vector>

/*
최적화 어떻게 하는 건데 빼애애개개개개애개액액애ㅐ애ㅐㅇㄱ
*/

using namespace std;

struct BST {
    int data;
    struct BST* left, * right;

    BST(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert_node(BST* node, int item, int& count) {
    if (!node) return;

    count++;
    if (node->data > item) {
        if (!node->left) {
            BST* new_node = new BST(item);
            node->left = new_node;
            return;
        }
        insert_node(node->left, item, count);
    }
    else if (node->data < item) {
        if (!node->right) {
            BST* new_node = new BST(item);
            node->right = new_node;
            return;
        }
        insert_node(node->right, item, count);
    }
}

void delete_node(BST* node) {
    if (!node) return;

    delete_node(node->left);
    delete_node(node->right);
    delete(node);
}

int main() {
    int N, k, count = 0;
    cin >> N >> k;
    
    BST* root = new BST(k);
    vector<int> data;
    for (int i = 1; i < N; i++) {
        scanf("%d", &k);
        data.push_back(k);
    }

    BST* root_temp;
    printf("%d\n", count);
    for (int i = 0; i < N-1; i++) {
        insert_node(root, data[i], count);
        printf("%d\n", count);
    }

    delete_node(root);

    return 0;
}