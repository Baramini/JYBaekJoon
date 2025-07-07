#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Node{
    int data;
    Node* parent;
    vector<Node*> child;

    Node(int item) : data(item), parent(nullptr) { child.clear(); }
};

int main() {
    vector<Node*> Nodes;
    Node* root = new Node(1);
    Nodes.push_back(root);

    int N;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        Node* node = new Node(i);
        Nodes.push_back(node);
    }

    list<int> vertex0;
    list<int> vertex1;
    for (int i = 0; i < N-1; i++) {
        int v0, v1;
        cin >> v0 >> v1;
        vertex0.push_back(v0);
        vertex1.push_back(v1);
    }

    list<int> parent_list;
    parent_list.push_back(0);
    while (!vertex0.empty()) {
        
    }

    for (int i = 1; i < N; i++) printf("%d\n", Nodes[i]->parent->data);
    for (int i = 0; i < N; i++) delete Nodes[i];
}