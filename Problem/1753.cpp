// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// struct Edge {
//     int dest;
//     int weight;

//     Edge(int d, int w) : dest(d), weight(w) {}
// };
// struct Vertex {
//     int data;
//     vector<Edge*> edges;

//     Vertex(int val) : data(val) {}
// };
// priority_queue<Vertex*> graph;

// void dijkstra(int start) {
//     priority_queue<Edge*, vector<Edge*>, greater<>> pq;

// }

// int main() {
//     int V, E, K;
//     cin >> V >> E >> K;
//     for (int i = 0; i <= V; i++) {
//         Vertex* v = new Vertex(i);
//         graph.push_back(v);
//     }

//     for (int i = 0; i < E; i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         Edge* e = new Edge(v, w);
//         graph[u]->edges.push_back(e);

//     }

//     dijkstra(K);

//     return 0;
// }