#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// We use a very large number to mean:
// "right now, we do not know any path to this node yet".
// Later, Dijkstra's algorithm will replace this with real distances.
const int INF = 1e9;

int main() {
    // V = number of vertices (nodes)
    // E = number of edges
    int V, E;
    cin >> V >> E;

    // Adjacency list representation of the graph.
    //
    // Explanation of the type:
    // vector< vector< pair<int, int> > > adj(V);
    //
    // - The outer vector has V positions, one for each vertex.
    // - adj[u] stores all neighbors of vertex u.
    // - Each pair<int, int> means:
    //     first  = neighboring vertex
    //     second = weight (cost) of the edge
    //
    // Example:
    // If there is an edge from 2 to 5 with weight 7,
    // then inside adj[2] we store {5, 7}.
    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Store the edge u -> v with weight w.
        adj[u].push_back({v, w});

        // Store the reverse edge v -> u as well.
        // Because of this line, the graph is being treated as UNDIRECTED.
        //
        // If your graph is directed, remove the next line.
        adj[v].push_back({u, w});
    }

    // The starting node from which shortest distances will be calculated.
    int source;
    cin >> source;

    // dist[i] = currently known shortest distance from source to ith node 
    // Start with INF for every node because we do not know any path yet.
    vector<int> dist(V, INF);

    // visited[i] becomes true after we permanently finalize
    // the shortest distance to node i.
    vector<bool> visited(V, false);

    // parent[i] stores the previous node on the shortest path to i.
    // This is useful if you want to reconstruct the actual path later.
    // -1 means "no parent known".
    vector<int> parent(V, -1);

    // Priority queue used as a MIN-HEAP.
    //
    // Each item in the queue is:
    // {distance_from_source, node}
    //
    // Why 'greater<pair<int, int>>'?
    // - By default, priority_queue in C++ is a max-heap.
    // - That means the largest element would come first.
    // - Dijkstra needs the SMALLEST distance first,
    //   so we use 'greater<...>' to reverse the behavior.
    //
    // The pair is compared lexicographically:
    // - first compare distance
    // - if distance is equal, compare node number
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    // Distance from source to itself is always 0.
    dist[source] = 0;

    // The source is the starting point, so it has no parent.
    parent[source] = -1;

    // Put the source into the priority queue.
    // This means: "we can reach source with cost 0".
    pq.push({0, source});  // This is the only known distance of a vertex from the source vertex. 

    while (!pq.empty()) {

        // The top element always has the smallest distance currently
        // because we are using a min-heap.
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Sometimes the same node can be inserted into the queue
        // multiple times with different distances.
        //
        // Once we have already finalized a node, we skip any old
        // extra copies of that node that may still remain in the queue.
        if (visited[u])
            continue;

        // Go through every edge leaving node u.
        // Each 'edge' contains:
        // edge.first  = neighbor vertex
        // edge.second = edge weight
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // This is the "relaxation" step, the heart of Dijkstra's algorithm.
            //
            // We ask:
            // "If we go from source -> ... -> u -> v,
            //  do we get a shorter path to v than the best one we knew before?"
            //
            // If yes:
            // - update dist[v]
            // - remember that we reached v from u
            // - push the improved distance into the priority queue
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }

        // We now mark u as visited, meaning:
        // "the shortest distance to u is finalized and will not improve anymore".
        visited[u] = true;
    }

    // Print the shortest distance from source to every vertex.
    cout << "Shortest distances:\n";
    for (int i = 0; i < V; i++)
        cout << i << " : " << dist[i] << endl;

    // Print parent information.
    // If you follow parent pointers backward from any node,
    // you can reconstruct the shortest path from the source.
    cout << "\nParents:\n";
    for (int i = 0; i < V; i++)
        cout << i << " <- " << parent[i] << endl;

    return 0;
}
