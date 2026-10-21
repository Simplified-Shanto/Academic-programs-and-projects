#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

const int V = 6;

enum vertex{
    A = 0, 
    B = 1, 
    C = 2, 
    D = 3, 
    E = 4, 
    F  = 5
}; 

// This is the same undirected adjacency-list graph used in the Prim's file.
// Each pair is {neighbour, edgeWeight}.
vector<vector<pair<int, int>>> graph = {
    {{B, 5}, {C, 7}},         // A / vertex 0
    {{A, 5}, {C, 9}, {D, 1}}, // B / vertex 1
    {{A, 7}, {B, 9}, {E, 2}}, // C / vertex 2
    {{B, 1}, {E, 3}, {F, 8}}, // D / vertex 3
    {{C, 2}, {D, 3}, {F, 5}}, // E / vertex 4
    {{D, 8}, {E, 5}}          // F / vertex 5
};

// Disjoint Set Union (DSU) stores which vertices are already connected by
// edges that Kruskal has selected.
struct DSU {
    vector<int> parent;
    vector<int> componentSize;

    DSU(int vertexCount) {
        parent.resize(vertexCount);
        componentSize.assign(vertexCount, 1);

        // Initially, each vertex is a separate component.
        for (int vertex = 0; vertex < vertexCount; vertex++) {
            parent[vertex] = vertex;
        }
    }

    // Returns the representative (root) of node's current component.
    // The assignment performs path compression: later find calls become fast.
    int find(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    // Joins the components containing u and v.
    // Returns false when they already belong to the same component, because
    // adding edge u--v then would create a cycle.
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) {
            return false;
        }

        // Attach the smaller component below the larger one.
        if (componentSize[rootU] < componentSize[rootV]) {
            swap(rootU, rootV);
        }

        parent[rootV] = rootU;
        componentSize[rootU] += componentSize[rootV];
        return true;
    }
};

int main() {
    // Kruskal processes every graph edge globally, in ascending weight order.
    // Each tuple is {weight, u, v}; putting weight first lets normal sort()
    // place the lightest edge first.
    vector<tuple<int, int, int>> edges;

    for (int u = 0; u < V; u++) {
        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // The graph is undirected, so u--v also appears as v--u in the
            // adjacency list. Keep only one copy of every undirected edge.
            if (u < v) {
                edges.push_back({weight, u, v});
            }
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(V);
    vector<tuple<int, int, int>> MST;
    long long mstTotalWeight = 0;

    for (const auto& edge : edges) {
        int weight = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);

        // Select the edge only when it connects two different components.
        // DSU therefore prevents cycles without marking vertices visited.
        if (dsu.unite(u, v)) {
            MST.push_back(edge);
            mstTotalWeight += weight;

            cout << "Selected edge: " << u << " --- " << weight
                 << " --- " << v << endl;

            // An MST of V vertices always contains exactly V - 1 edges.
            if (static_cast<int>(MST.size()) == V - 1) {
                break;
            }
        } else {
            cout << "Skipped edge: " << u << " --- " << weight
                 << " --- " << v << " (would create a cycle)" << endl;
        }
    }

    // If fewer than V - 1 edges were selected, at least one component could
    // not be connected to the others, so the graph has no spanning tree.
    if (static_cast<int>(MST.size()) != V - 1) {
        cout << "Graph is disconnected; no spanning tree exists." << endl;
        return 0;
    }

    cout << "\nTotal MST weight = " << mstTotalWeight
         << " with the edges:" << endl;

    for (const auto& edge : MST) {
        cout << get<1>(edge) << " --- " << get<0>(edge)
             << " --- " << get<2>(edge) << endl;
    }

    return 0;
}
