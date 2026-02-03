#include <stdio.h>
#include <stdlib.h>

#define V 10

typedef struct Node
{
    int data; // This will store the index of the vertex with which the current node has connection with.
    struct Node *nextNodePtr;
} Node;

Node *createNodePtr(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNodePtr = NULL;
}

void insertEdge(Node *Graph[V], int node1Index, int node2Index)
{
    Node *newNode = createNodePtr(node2Index);
    if (Graph[node1Index] == NULL) // node1 has currently no connection with any other nodes of the graph.
    {
        Graph[node1Index] = newNode;
        printf("Inserted the first edge (%d, %d) for node %d\n", node1Index, node2Index, node1Index);
    }
    else // node 1 has some connection with other nodes in the graph, and we want to add some nodes to it - at the beginning of that list.
    {
        newNode->nextNodePtr = Graph[node1Index]; // We'll always track the latest inserted node in the graph.
        Graph[node1Index] = newNode;
        printf("Inserted an edge (%d, %d/)\n", node1Index, node2Index);
    }
}

void deleteEdge(Node *Graph[V], int node1Index, int node2Index)
{
    if (node1Index >= V || node2Index >= V)
    {
        printf("Invalid node index! Can't delete Edge\n");
        return;
    }

    // First node is the deletable 1
    Node *currentNodePtr = Graph[node1Index]; // We also need the previous node to the current node for deletion.
    if (currentNodePtr->data == node2Index)
    {
        Graph[node1Index] = currentNodePtr->nextNodePtr;
        free(currentNodePtr);
        return;
    }

    Node *previousNodePtr = currentNodePtr;
    while (currentNodePtr->data != node2Index)
    {
        previousNodePtr = currentNodePtr;
        currentNodePtr = currentNodePtr->nextNodePtr;
    }

    previousNodePtr->nextNodePtr = currentNodePtr->nextNodePtr;
    free(currentNodePtr);

    printf("Deleted the edge(%d, %d)\n", node1Index, node2Index);
}

void printGraph(Node *Graph[V])
{
    for (int i = 0; i < V; i++)
    {
        Node *currentNodePtr = Graph[i];
        printf("[%d]: ", i);
        while (currentNodePtr != NULL)
        {
            printf("%d ", currentNodePtr->data);
            currentNodePtr = currentNodePtr->nextNodePtr;
        }
        printf("\n");
    }
}

void findEdge(Node *Graph[V], int node1Index, int node2Index)
{
    if (node1Index >= V || node2Index >= V)
    {
        printf("Invalid node indices, can't search the eadge!\n");
        return;
    }

    Node *currentNodePtr = Graph[node1Index];
    while (currentNodePtr != NULL)
    {
        if (currentNodePtr->data == node2Index)
        {
            printf("Edge (%d, %d) is found in the graph\n", node1Index, node2Index);
            return;
        }
        currentNodePtr = currentNodePtr->nextNodePtr;
    }
    printf("Edge (%d, %d) is not found in the graph\n", node1Index, node2Index);
}

// The following implementation is kind of unidirectional
int main()
{

    Node *Graph[V] = {NULL}; // This array will store pointer of nodes.
    insertEdge(Graph, 1, 2);
    insertEdge(Graph, 1, 3);
    insertEdge(Graph, 2, 4);
    insertEdge(Graph, 2, 1);
    insertEdge(Graph, 3, 4);
    printGraph(Graph);
    deleteEdge(Graph, 1, 2);
    printGraph(Graph);
    findEdge(Graph, 1, 3); 
    return 0;
}