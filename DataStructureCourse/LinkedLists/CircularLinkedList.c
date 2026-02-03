// The major difference with the singly linked list is that, here we track both the First and last pointers of the list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *nextNodePtr;
} Node;

Node *createNodePtr(int data)
{
    Node *newNodePtr = malloc(sizeof(Node));
    newNodePtr->nextNodePtr = data;
    newNodePtr->nextNodePtr = NULL;
}

void printList(Node *firstNodePtr, Node *lastNodePtr)
{
    if (firstNodePtr == NULL)
    {
        printf("Empty List! Nothing to Print\n");
        return;
    }

    Node *currentNodePtr = firstNodePtr;
    printf("List: ");
    while (1)
    {
        printf("%d ", currentNodePtr->data);
        if (currentNodePtr == lastNodePtr)
            break;
        currentNodePtr = currentNodePtr->nextNodePtr;
    }
}


//Insertion at any index of a circular linked list 
Node* insertNode(Node* firstNodePtr, Node* lastNodePtr,int index, int value)
{
    
}

Node *headNodePtr; 


int main()
{


    return 0; 
}