#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char item) : data(item), left(nullptr), right(nullptr) {}
};

Node* search_node(Node* node, char item) {
    if (!node) return nullptr;
    if (node->data == item) return node;

    Node* left_node = search_node(node->left, item);
    if (left_node) return left_node;

    return search_node(node->right, item);
}

void preorder_print(Node* node) {
    if (!node) return;

    printf("%c", node->data);
    preorder_print(node->left);
    preorder_print(node->right);
}
void inorder_print(Node* node) {
    if (!node) return;

    inorder_print(node->left);
    printf("%c", node->data);
    inorder_print(node->right);
}
void postorder_print(Node* node) {
    if (!node) return;

    postorder_print(node->left);
    postorder_print(node->right);
    printf("%c", node->data);
}
void delete_tree(Node* node) {
    if (!node) return;

    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

int main() {
    int N;
    cin >> N;

    Node* root = new Node('A');

    for (int i = 0; i < N; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        Node* node = search_node(root, p);
        if (l != '.') node->left = new Node(l);
        if (r != '.') node->right = new Node(r);
    }

    preorder_print(root);
    printf("\n");
    inorder_print(root);
    printf("\n");
    postorder_print(root);

    delete_tree(root);
}