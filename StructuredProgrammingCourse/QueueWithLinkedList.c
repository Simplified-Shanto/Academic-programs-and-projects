/*
have a head node and tail node.
Enqueue() - Adds an element in the tail of the list (one more person comes in the queue)
Dequeue() - Removes the node from the front of the list (the first person in the queue is served)
Peek() - Gives the data of the first node
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNodePtr;
    newNodePtr = malloc(sizeof(Node));
    newNodePtr->data = value;
    newNodePtr->next = NULL;

    return newNodePtr;
}


void enqueue(Node **headNodePtr, Node **tailNodePtr, int value)
{
    Node *newNodePtr = createNode(value);
    if (*tailNodePtr == NULL) // Empty queue
    {
        *headNodePtr = *tailNodePtr = newNodePtr;
    }
    else
    {
        (*tailNodePtr)->next = newNodePtr;
        *tailNodePtr = newNodePtr;
    }
}

void dequeue(Node **headNodePtr, Node **tailNodePtr)
{
    if (*headNodePtr == NULL)
    {
        printf("Queue underflow! Cannot dequeue.\n");
        return;
    }
    Node *tempNodePtr = *headNodePtr;
    *headNodePtr = (*headNodePtr)->next;
    if (*headNodePtr == NULL) // Queue became empty
        *tailNodePtr = NULL;
    free(tempNodePtr);
}


void printDequeue(Node *headNodePtr)
{
    printf("Queue: "); 
    while (headNodePtr != NULL)
    {
        printf("%d ", headNodePtr->data);
        headNodePtr = headNodePtr->next;
    }
    printf("\n");
}

int peek(Node *headNodePtr)
{
    return headNodePtr->data;
}

int isDequeEmpty(Node *headNodePtr)
{
    if (headNodePtr == NULL)
    {
        return 1;
    }
    return 0;
}

int main()
{
    Node *tailNodePtr = NULL;
    Node *headNodePtr = NULL;
    printf("Deck empty: %d\n", isDequeEmpty(headNodePtr));
    enqueue( &headNodePtr,&tailNodePtr, 1);
    printDequeue(headNodePtr);
     enqueue( &headNodePtr,&tailNodePtr, 2);
    printDequeue(headNodePtr);
     enqueue( &headNodePtr,&tailNodePtr, 3);
    printDequeue(headNodePtr);

    printf("Deck empty: %d\n", isDequeEmpty(headNodePtr));
    printf("First element in the deck is %d\n", peek(headNodePtr));
    printDequeue(headNodePtr);
    dequeue(&headNodePtr, &tailNodePtr);
    printDequeue(headNodePtr);
    dequeue(&headNodePtr, &tailNodePtr);
    dequeue(&headNodePtr, &tailNodePtr);
    printDequeue(headNodePtr);
    printf("Deck empty: %d\n", isDequeEmpty(headNodePtr));

    return 0;
}
