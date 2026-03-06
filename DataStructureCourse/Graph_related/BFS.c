#include <stdio.h>
#include <stdbool.h>

#define V 6
int graph[V][V];
bool visited[V];

void bfs(int startVertex)
{
    int queue[V];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < V; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    printf("Enter the matrix with %d vertices as a %d x %d adjacency matrix: \n", V, V, V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("DFS list: \n");
    bfs(0);

    return 0;
}

// Adjacency matrix based DFS application

// #include<stdio.h>
// #include<stdbool.h>

// #define max_vertices 20

// int adjMatrix[max_vertices][max_vertices];
// bool visited[max_vertices];
// int numVertices;

// // Recursive DFS function
// void dfs(int currentVertex)
// {
//     int i;
//     printf("%d ", currentVertex); // currentVertex is being processed now.
//     visited[currentVertex] = true; // mark the current Vertex as visited

//     // Recursively search for all unvisited adjacent vertices
//     for (i = 0; i < numVertices; i++)
//     {
//         if(adjMatrix[currentVertex][i] == 1 && visited[i]!=1) // If the current vertex has an edge with the vertex with index i and vertex i has not been visited yet.
//         {
//             dfs(i);
//         }
//     }
// }

// int main()
// {
//     int i, j;
//     int startVertex;

//     printf("Enter number of vertices: ");
//     scanf("%d", &numVertices);

//     printf("Enter the adjacency matrix (0 or 1):\n");
//     for (i = 0; i < numVertices; i++)
//     {
//         for (j = 0; j < numVertices; j++){
//             scanf("%d", &adjMatrix[i][j]);
//         }
//     }

//     // Initialize all nodes as not visited
//     for (i = 0; i < numVertices; i++)
//     {
//         visited[i] = false;
//     }

//     printf("Enter the starting vertex (0 to %d): ", numVertices - 1);
//     scanf("%d", &startVertex);

//     printf("Depth First Search starting from vertex %d: ", startVertex);
//     dfs(startVertex);

//     printf("\n");

//     return 0;
// }