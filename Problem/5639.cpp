#include <iostream>

using namespace std;

struct BST {
    int data;
    struct BST* left, * right;

    BST(int val) : data(val), left(nullptr), right(nullptr) {}
};

void insert_node(BST* root, int val) {
    BST* node = root;
    while (node) {
        if (node->data > val) {
            if (!(node->left)) {
                BST* new_node = new BST(val);
                node->left = new_node;
                return;
            }
            node = node->left;
        }
        else {
            if (!(node->right)) {
                BST* new_node = new BST(val);
                node->right = new_node;
                return;
            }
            node = node->right;
        }
    }
}

void print_postorder(BST* node) {
    if (!node) return;

    print_postorder(node->left);
    print_postorder(node->right);
    printf("%d\n", node->data);
}
void delete_BST(BST* node) {
    if (!node) return;

    delete_BST(node->left);
    delete_BST(node->right);
    delete(node);
}

int main() {
    int x;
    cin >> x;
    BST* root = new BST(x);

    while (cin >> x && x != -1) insert_node(root, x);

    print_postorder(root);

    delete_BST(root);

    return 0;
}