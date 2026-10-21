#include<algorithm> 
#include<iostream> 
#include<queue> 
using namespace std; 

#define vertexCount 6


// Adjacency list representation: 
vector<vector<pair<int, int>>> graph = {
{{1, 5}, {2, 6}}, 
{{0, 5}, {2, 7}, {3, 4}}, 
{{0, 6}, {1, 7}, {4, 8}}, 
{{1, 4}, {4, 2}, {5, 4}}, 
{{2, 8}, {3, 2}, {5, 3}}, 
{{4, 3}, {3, 4}}
};

vector<int> minDistance(vertexCount, INT32_MAX);  

int main()
{
    int startingNodeIndex = 0, destinationNodeIndex = 5; 

    // we'll store the {distance, node} here, distance = distance from the source node
    priority_queue<pair<int, int>, 
    vector<pair<int, int>>, 
    greater<pair<int, int>>
    > pq; 

    pq.push({ 0, startingNodeIndex}); // distance , nodeIndex
    minDistance[startingNodeIndex] = 0; 

    while(!pq.empty())
    {
        auto checkingNode = pq.top(); // checking node will be the node with minimum edgeWeight
        pq.pop(); 

        unsigned currentNodeIndex = checkingNode.second; 
        unsigned currentNodeMinDistance = checkingNode.first; 

        // comparing the recorded distance and the distance at the time it was pushed in the queue of this checking node 
        if(currentNodeMinDistance <= minDistance[currentNodeIndex]){
            minDistance[currentNodeIndex] = currentNodeMinDistance; 
        }
        else // We can't improve the distance for this node. 
        {
            continue; 
        }

        //We come to this point only if the currentNodeMinDistance <= minDistance[currentNodeIndex], otherwise we visit the neighbours of some other node whose minimum distance can be improved 
        for(int i = 0; i<graph[currentNodeIndex].size(); i++) // Traversing the neighbours of the current node 
        {
            int edgeWeight = graph[currentNodeIndex][i].second; 
            int neighbour_node_index = graph[currentNodeIndex][i].first; 
            int candidate_distance = currentNodeMinDistance + edgeWeight; 

            if(candidate_distance < minDistance[neighbour_node_index]){
                minDistance[neighbour_node_index] = candidate_distance; 
                pq.push({candidate_distance, neighbour_node_index}); 
            }
        }
    }


    cout << endl << "ShortestDistance = " << minDistance[destinationNodeIndex] << endl; 

    cout << "Min distances are: " ; 
    for(int i = 0; i<vertexCount; i++)
    {
        cout << minDistance[i] << " "; 
    } cout << endl; 


    return 0; 
}