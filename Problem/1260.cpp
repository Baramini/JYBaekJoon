#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct Vertex {
    int data;
    int visited;
    set<int> vertices;

    Vertex(int val) : data(val), visited(0) {}
};
vector<Vertex*> Graph;

void DFS(Vertex* vertex) {
    vertex->visited++;
    printf("%d ", vertex->data);

    for (int next : vertex->vertices) {
        if (Graph[next]->visited < 1) DFS(Graph[next]);
    }
}

void BFS(Vertex* start) {
    queue<Vertex*> not_visited;

    not_visited.push(start);
    start->visited++;

    while (!not_visited.empty()) {
        Vertex* v = not_visited.front();
        not_visited.pop();
        printf("%d ", v->data);

        for (int next : v->vertices) {
            if (Graph[next]->visited < 2) {
                not_visited.push(Graph[next]);
                Graph[next]->visited++;
            }
        }
    }
}

int main() {
    int N, M, V;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &V);

    for (int i = 0; i <= N; i++) {
        Vertex* vertex = new Vertex(i);
        Graph.push_back(vertex);
    }

    for (int i = 0; i < M; i++) {
        int j, k;
        scanf("%d", &j);
        scanf("%d", &k);
        Graph[j]->vertices.insert(k);
        Graph[k]->vertices.insert(j);
    }

    DFS(Graph[V]);
    printf("\n");
    BFS(Graph[V]);

    for (int i = 0; i <= N; i++) delete(Graph[i]);

    return 0;
}