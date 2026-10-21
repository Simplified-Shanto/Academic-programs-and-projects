#include<algorithm> 
#include<iostream> 
#include<climits>
#include<vector> 
#include<tuple> 
#include<queue> 
#include<functional> // greater, used to make the priority queue a min heap
#include<utility> // pair, used in the adjacency list

using namespace std; 

const int V = 6; 


vector<vector<pair<int, int> >> graph = 
{{{1, 5}, {2, 7}},         //A
 {{0, 5}, {2, 9}, {3, 1}}, //B
 {{0, 7}, {1, 9}, {4, 2}}, //C
 {{1, 1}, {4, 3}, {5, 8}}, //D
 {{2, 2}, {3, 3}, {5, 5}}, //E
 {{3, 8}, {4, 5}}          //F
}; 


bool visited[V]  = {false}; 


//Since weight is the first value in the tuple, the queue primarily sorts according to weight 
priority_queue< 
    tuple<int, int, int>, // each item of the priority queue stores weight, node, parent
    vector<tuple<int, int, int>>, 
    greater<tuple<int, int, int>> // makes it a min heap 
    > pq; 

/*
Above priority queue object creation can be read as: 
priority_queue < 
    what_we_store, 
    container_used_internally, 
    comparison_rule
>

*/
vector<tuple<int, int, int>> MST; 
long long mstTotalWeight = 0; // The sum of several int edge weights may exceed int's range.

int totalVisited = 0; // Counts distinct visited vertices to detect a disconnected graph.

int main()
{
// Suppose Prim starts from vertex 0
pq.push({0, 0, -1}); // weight = 0 because we aren't using an edge to reach the starting vertex
// parent = -1 because vertex 0 doesn't have a parent yet. 
 
// Check for an empty queue before top(); a disconnected graph can run out of edges.
while(!pq.empty() && totalVisited < V){
    auto current = pq.top(); 
    pq.pop(); 
    int weight = get<0>(current); 
    int node =   get<1>(current); 
    int parent = get<2>(current); 
     // Several edges can put the same node in the queue. Skip old entries
     // after that node is visited, so it and its edge are not counted twice.

     if(visited[node]){ continue; }
     visited[node] = true;
     totalVisited++; // Increment only when visiting a node for the first time.
      
     cout <<  endl << "PQ top: " << "weight: " << weight << " node: " << node << " parent: " << parent << endl; 

    // The initial entry {0, 0, -1} selects the start; it is not a real edge.
    if(parent != -1){
        MST.push_back(current);
        mstTotalWeight+=weight;
    }

    for(auto edge: graph[node]){
        int edgeWeight = edge.second; 
        int neighbour = edge.first; 

        if(visited[neighbour]==false){
            pq.push({edgeWeight, neighbour, node}); 
            cout << "Inserting unvisited neighbour " << neighbour << " of node " << node << " into the queue" << endl; 
            
        }
    }
}


// If some vertices are unreachable from the start, these edges only span
// its connected component; they are not an MST of the entire graph.
if(totalVisited != V){
    cout << "Graph is disconnected; no spanning tree exists." << endl;
    return 0;
}

cout << endl << "Total MST weight = " << mstTotalWeight << " with the edges: " << endl;
// MST now contains only real edges, so print every entry.
for(const auto& edge : MST)
{
    cout << get<1>(edge) << " --- " << get<0>(edge) << " --- " << get<2>(edge) << endl; 
}

}
