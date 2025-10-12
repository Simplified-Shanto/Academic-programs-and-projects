// Implement stack data structure using the concept of linked list with the following functionalities
// push() -> to insert an element at the rightmost position
// Pop()  -> to remove the rightmost element
// Push() -> to insert at a particular index
// isEmpty() -> to indicate whether the stack is empty.

// Implement a linked list to add an element at any position of a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;


void freeMemory(Node *leftMostNodePtr)
{
    while (leftMostNodePtr != NULL)
    {
        Node *temp = leftMostNodePtr->next;
        free(leftMostNodePtr);
        leftMostNodePtr = temp;
    }
}

void push(Node **TopNodePtr, int value) // Pass the pointer by reference (using a double pointer)
{
    Node *newNodePtr;
    newNodePtr = malloc(sizeof(Node));
    newNodePtr->data = value;
    newNodePtr->next = *TopNodePtr;   // The bottom Node in this stack is in the rightmost place when we think it to be a horizontal list. And it's pointing to NULL. 
                                      // Top → [10] → [20] → [30] → NULL | If this is the current status of the stack
                                      // Top → [40] → [10] → [20] → [30] → NULL | This is the status after we add the element 40 in the list. 
    (*TopNodePtr) = newNodePtr;
}

void pop(Node **TopNodePtr) // Pass the pointer by reference (using a double pointer)
{
    if (*TopNodePtr == NULL)
    {
        printf("Stack underflow! Cannot pop from empty stack.\n");
        return;
    }

    Node *temporaryNodePtr = (*TopNodePtr)->next; // Storing the address of the second to top element in the stack
    free(*TopNodePtr); //Freeing up the memory used to store the top node contents.
    *TopNodePtr = temporaryNodePtr; // Assigning the address of the second to top Node to the Null pointer. 
}


int top(Node *topNodePointer)
{
    return topNodePointer->data; 
}

int isEmpty(Node *leftMostNodePtr)
{
    if(leftMostNodePtr == NULL) {
        return 1; 
    }
    else 
    {
        return 0; 
    }
}






int main()
{

    Node *Top = NULL;
    printf("IsEmpty(): %d\n", isEmpty(Top));

    push(&Top, 10);

    printf("Curren top element: %d\n", top(Top)); 

    push(&Top, 20);

    printf("Curren top element: %d\n", top(Top)); 

    push(&Top, 30);

    printf("Curren top element: %d\n", top(Top));

    pop(&Top); 

    printf("Curren top element: %d\n", top(Top));

    freeMemory(Top); // Frees all the memory addresses pointed by Top , it doesn't free Top
    Top = NULL; 
    printf("IsEmpty(): %d\n", isEmpty(Top));


    return 0;
}
