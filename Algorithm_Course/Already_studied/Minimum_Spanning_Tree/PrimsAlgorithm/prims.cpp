#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // undirected graph
    }

    int source;
    cin >> source;

    vector<int> key(V, INF);      // minimum edge weight to reach node
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    // (weight, node)
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    key[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {

        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;



        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
        visited[u] = true;
    }

    // Output MST edges
    cout << "\nMST Edges:\n";
    int totalCost = 0;

    for (int i = 0; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i
                 << " (weight = " << key[i] << ")\n";
            totalCost += key[i];
        }
    }

    cout << "\nTotal MST Cost = " << totalCost << endl;

    return 0;
}
