#include<algorithm> 
#include<iostream> 
using namespace std; 

#define vertexCount 6

int graph[vertexCount][vertexCount] = {
    {0, 4, 2, 0, 0, 0}, 
    {4, 0, 5, 7, 0, 0}, 
    {2, 5, 0, 0, 2, 0}, 
    {0, 7, 0, 0, 4, 5}, 
    {0, 0, 2, 4, 0, 9}, 
    {0, 0, 0, 5, 9, 0}
}; 

vector<string> nodeStatus(vertexCount, "unreached"); // reached[i] says us whether the ith node is reached or not
vector<int> minDistance(vertexCount, INT32_MAX);  

int main()
{
    int startingNodeIndex = 0, destinationNodeIndex = 5; 
    // cout << "Enter starting node's index and destination node's index: "; 
    // cin >> startingNodeIndex >> destinationNodeIndex; 

    vector<pair<int, int>> checkingNodes;

    checkingNodes.push_back({ 0, startingNodeIndex}); // distance , nodeIndex
    minDistance[startingNodeIndex] = 0; 
    nodeStatus[startingNodeIndex] = "checking"; 

    while(checkingNodes.size()!=0)
    {
        sort(checkingNodes.begin(), checkingNodes.end()); 
        unsigned currentNodeIndex = checkingNodes[0].second; 
        unsigned currentNodeMinDistance = checkingNodes[0].first; 

        cout << endl << "Current Node Index: " << currentNodeIndex << endl; 
        cout << "Checking index list: "; for(int i = 0; i < checkingNodes.size(); i++)  cout << checkingNodes[i].second << " "; cout <<  endl << endl; 


        for(int i = 0; i < vertexCount; i++) // checking all other vertices against the first node of the checking nodes, which currently has the minimum distance among the checking nodes 
        {

            if(graph[currentNodeIndex][i]!=0 && nodeStatus[i]!="reached") // whether we have an edge in between i and checkingNodes[0].first
            { 
               int edgeWeight = graph[currentNodeIndex][i]; 

               if(nodeStatus[i]=="unreached") {

                minDistance[i] = currentNodeMinDistance + graph[currentNodeIndex][i]; 
                cout << "Current Node MinDistance: " << currentNodeMinDistance << endl; 
                cout << " edgeWeight  = " << edgeWeight <<  endl; 
                cout <<"Unreached node " << i <<  " minD = " << currentNodeMinDistance + edgeWeight << endl; 
                checkingNodes.push_back({minDistance[i], i}); 
                nodeStatus[i] = "checking"; 

               }
               else if(nodeStatus[i]=="checking"){
                
                minDistance[i] = min(int(minDistance[i]), int(currentNodeMinDistance + graph[currentNodeIndex][i])); 
                cout << "Current Node MinDistance: " << currentNodeMinDistance << endl; 
                cout << " edgeWeight  = " << edgeWeight <<  endl; 
                cout << "checking node " << i << " minD = " << minDistance[i] << endl << endl; 
                
               }

               cout << "Min distances are: "; for(int i = 0; i<vertexCount; i++) cout << minDistance[i] << " "; cout << endl << endl; 
            }
        }

        nodeStatus[currentNodeIndex] = "reached"; 
        checkingNodes.erase(checkingNodes.begin()); 
    }


    cout << endl << "ShortestDistance = " << minDistance[destinationNodeIndex] << endl; 

    cout << "Min distances are: " ; 
    for(int i = 0; i<vertexCount; i++)
    {
        cout << minDistance[i] << " "; 
    } cout << endl; 


    return 0; 
}