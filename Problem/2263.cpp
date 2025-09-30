#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> inorder_vec;
vector<int> postorder_vec;
unordered_map<int, int> inorder_index_map;

struct Tree {
    int data;
    struct Tree* left, * right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 후위 순회에서 루트노드 찾기
// 중위 순회에서 루트에 해당하는 인덱스를 받아서 왼쪽, 오른쪽 서브트리로 나누기
// 왼쪽 오른쪽 서브트리의 노드의 개수도 파라미터로 전달해서 반영
// 터미널 노드까지 가면 left, right각각 연결하기 - Divide and Conquer
Tree* make_tree(int root_index, int min_index, int max_index, int& postorder_root_index) {
    int count = max_index - min_index;
    if (count < 0) return nullptr;
    else if (count < 1) {
        int root_index = inorder_index_map.at(postorder_vec[--postorder_root_index]);
        Tree* newNode = new Tree(inorder_vec[root_index]);

        return newNode;
    }
    else {
        int root_index = inorder_index_map.at(postorder_vec[--postorder_root_index]);
        Tree* root = new Tree(inorder_vec[root_index]);

        root->right = make_tree(root_index, root_index + 1, max_index, postorder_root_index);
        root->left = make_tree(root_index, min_index, root_index - 1, postorder_root_index);

        return root;
    }
}

void print_preorder(Tree* root) {
    printf("%d ", root->data);
    if (root->left != nullptr) print_preorder(root->left);
    if (root->right != nullptr) print_preorder(root->right);
}

void delete_tree(Tree* root) {
    if (root->left != nullptr) delete_tree(root->left);
    if (root->right != nullptr) delete_tree(root->right);
    delete(root);
}

int main() {
    int n, k;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        inorder_vec.push_back(k);
        inorder_index_map[k] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        postorder_vec.push_back(k);
    }

    int postorder_root_index = n - 1;
    int root_data = k;
    int root_index = inorder_index_map.at(root_data);

    Tree* root = new Tree(root_data);
    root->right = make_tree(root_index, root_index + 1, n - 1, postorder_root_index);
    root->left = make_tree(root_index, 0, root_index - 1, postorder_root_index);

    print_preorder(root);

    delete_tree(root);
}