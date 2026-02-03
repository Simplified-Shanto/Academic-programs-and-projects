#include<stdio.h> 

#define V 4 

void addEdge(int mat[V][V], int v1, int v2)
{
    mat[v1][v2] = 1; 
}


void printGraph(int mat[V][V])
{
    for (int i = 0; i<V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", mat[i][j]); 
        }
        printf("\n"); 
    }

     printf("\n");  
}


int main()
{
int G[V][V];

for (int i = 0; i<V; i++)
{
    for (int j = 0; j < V; j++)
    {
        G[i][j] = 0;
       // printf("%d ", G[i][j]); 
    }
  //  printf("\n"); 
}

addEdge(G, 1, 1);
printGraph(G);
addEdge(G, 2, 0); 
printGraph(G); 

return 0; 
}