#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2100000000;

void dijkstra(vector<vector<pair<int, int>>>& edges, vector<int>& dist, int start_vertex) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> vertices;
    vertices.push(pair(0, start_vertex));

    while (!vertices.empty()) {
        auto[d, cur] = vertices.top();
        vertices.pop();

        if (d > dist[cur]) continue;

        for (const auto& [next, weight] : edges[cur]) {
            if (dist[next] > dist[cur] + weight) {
                dist[next] = dist[cur] + weight;
                vertices.push(pair(dist[next], next));
            }
        }
    }
}

int main() {
    int V, E, K;
    cin >> V >> E >> K;

    vector<int> dist;
    dist.assign(V, INF);
    dist[K-1] = 0;

    vector<vector<pair<int, int>>> edges(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u-1].push_back(make_pair(v-1, w));
    }

    dijkstra(edges, dist, K-1);

    for (const auto& d : dist) {
        if (d == INF) printf("INF\n");
        else printf("%d\n", d);
    }

    return 0;
}