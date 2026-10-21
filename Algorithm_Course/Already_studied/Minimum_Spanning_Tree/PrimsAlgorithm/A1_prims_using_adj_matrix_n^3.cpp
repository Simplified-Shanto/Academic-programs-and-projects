#include<algorithm> 
#include<iostream> 
#include<climits> 
using namespace std; 

const int V = 6; 

// Adjacency matrix representation of the graph 
int graph[V][V] = {
    {0, 5, 7, 0, 0, 0},
    {5, 0, 9, 1, 0, 0},
    {7, 9, 0, 0, 2, 0},
    {0, 1, 0, 0, 3, 8},
    {0, 0, 2, 3, 0, 5},
    {0, 0, 0, 8, 5, 0}
};


vector<int> reached; 



vector<int> unreached; 
vector<pair<int, int>> mst_edge; 
int mst_total_weight = 0; 


int main()
{
reached.push_back(0);
for(int i = 1; i< V; i++)
{
    unreached.push_back(i); 
}

while(unreached.size()!=0)
{
    cout << "Reached list: "; for(int i =0; i < reached.size(); i++) cout << reached[i] << " "; cout << endl; 
    cout << "Unreached list: "; for(int i = 0; i< unreached.size(); i++) cout << unreached[i] << " "; cout << endl; 
    int minEdgeWeight = INT_MAX; 
    int reachedNodeIndex, unreachedNodeIndex; 

    for(int i = 0; i < unreached.size(); i++)
    {
        for(int j = 0; j < reached.size(); j++)
        {
            int edgeWeight = graph[unreached[i]][reached[j]]; 

            if(edgeWeight!=0 && edgeWeight < minEdgeWeight) 
            {
                minEdgeWeight = edgeWeight; 
                reachedNodeIndex = j; 
                unreachedNodeIndex =  i; 
            }
        }   
    }

    cout << "minEdgeWeight = " << minEdgeWeight << " found between node " << reached[reachedNodeIndex] << " and " << unreached[unreachedNodeIndex] << endl  <<endl; 

    mst_edge.push_back({reached[reachedNodeIndex], unreached[unreachedNodeIndex]}); 
    mst_total_weight+=minEdgeWeight; 
    reached.push_back(unreached[unreachedNodeIndex]); 
    unreached.erase(unreached.begin() + unreachedNodeIndex); 
}

cout << "Sum of edge weights in the mst: " << mst_total_weight << endl; 
cout << "This mst has the following edges: " << endl; 
for(int i = 0; i < mst_edge.size(); i++)
{
    cout << mst_edge[i].first << " -----  " << mst_edge[i].second << endl; 
}

    return 0; 
}