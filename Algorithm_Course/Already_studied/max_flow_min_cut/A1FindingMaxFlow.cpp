#include <iostream>
#include <vector>
#include <algorithm> 
#include <climits> 

using namespace std;

const int V = 6;

enum Vertex {
    S = 0,
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    T = 5
};

bool findAugmentingPath (
    int currentNode, 
    const vector<vector<int>>& residual, 
    vector<bool>& visited, 
    vector<int>& parent
)
{
    //Base condition: DFS successfully reached the sink
    if(currentNode == T){
        return true; 
    }
        visited[currentNode] = true; 
        // Try every possible directed edge: currentNode -> nextNode. 
        for(int nextNode = 0; nextNode < V; nextNode++)
        {
            //DFS can use an edge only when residual capacity remains. 
            if(visited[nextNode]==0 && residual[currentNode][nextNode] > 0){
                // Remember how we reached nextNode. 
                parent[nextNode] = currentNode; 
                // Continue searching from nextNode. 
                if (findAugmentingPath(nextNode, residual, visited, parent)){
                    return true; 
                }
            }
        }
    // No path from currentNode to T was found 
    return false; 
}

int main() {
    vector<vector<int>> capacity(V, vector<int>(V, 0));

    // capacity[from][to] is the capacity of the directed edge from -> to.
    // The reverse entries remain 0 because the original graph is directed.
    capacity[S][A] = 10;
    capacity[S][C] = 10;
    capacity[A][B] = 4;
    capacity[A][D] = 8;
    capacity[C][D] = 9;
    capacity[D][T] = 10;
    capacity[D][B] = 6;
    capacity[B][T] = 10;

    // Initially, every residual capacity equals the original capacity.
    vector<vector<int>> residual = capacity;

    vector<bool> visited(V, false); 
    vector<int> parent(V, -1); // remembers how DFS reached that vertex. 


    int maxFlow = 0; 
    while (true)
    {
        //DFS needs fresh tracking for each new path search. 
        fill(visited.begin(), visited.end(), false); 
        fill(parent.begin(), parent.end(), -1); 

        bool pathFound = findAugmentingPath(S, residual, visited, parent); 

        //No remaining S -> T path means no more flow can be sent. 
        if(!pathFound)
        {
        break;   
        }

        int pathFlow = INT_MAX; 
        int currentNode  = T; 

        // Move backward: T -> ... -> S, using the parent array to find bottleneck capacities 
       while(currentNode!=S)
       {
        int previousNode = parent[currentNode]; 
        // The path can carry only as much flow as its smallest edge capacity. 
        pathFlow = min(pathFlow, residual[previousNode][currentNode]); 
        currentNode = previousNode; 
       }

       //Move backward throuhg the path again and update the residual capacities we just found. 
       currentNode = T; 

       while(currentNode!=S){
        int previousNode = parent[currentNode]; 
        //Forward edge loses the flow we just sent. 
        residual[previousNode][currentNode]-=pathFlow; 
        //Reverse edge gains that amount, allowing this flow to be undone later 
        residual[currentNode][previousNode]+=pathFlow; 
        currentNode = previousNode; 
       }

        //This path successfully adds pathFlow units to the total flow 
        maxFlow += pathFlow; 
        cout << "Added flow: " << pathFlow << endl; 
    } 

    cout << "Maximum flow: " << maxFlow << endl; 
    return 0;
}
