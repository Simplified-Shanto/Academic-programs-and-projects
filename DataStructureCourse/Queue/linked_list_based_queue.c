#include<stdio.h>
#include<stdlib.h> 


typedef struct Node{
    int data;
    struct Node *nextNodePtr; 
} Node;

Node *frontNodePtr, *rearNodePtr; // These NodePtr are not initialized since declared in the global scope so, frontNodePtr = rearNodePtr = NULL


void printQueue()
{
    Node *currentNodePtr = frontNodePtr;
    printf("rear end: "); 
    while(currentNodePtr!=NULL)
    {
        printf("%d ", currentNodePtr->data);
        currentNodePtr = currentNodePtr->nextNodePtr; 
    }
    printf(" : front end\n"); 
}





void enqueu(int value)
{
    Node *newNodePtr = (Node*)malloc(sizeof(Node));
    newNodePtr->data = value; 
    newNodePtr->nextNodePtr = NULL; 


    if(rearNodePtr==NULL) //We are enqueing an element to an empty queue. 
    {
        rearNodePtr = newNodePtr;
        frontNodePtr = newNodePtr;
        printf("%d is entered in the empty queue\n", value); 
    }
    else  // We are enqueing an element to a non-empty queue. 
    {
        newNodePtr->nextNodePtr = frontNodePtr; //Think of Next as Prev here, because, the top element is pointing to the element just below it in the stack. 
        //At this point our new_node_ptr holds the correct link with the previous element in the stack. 
        //But the global variable frontNodePtr is supposed to hold the most recently entered  element in the stack.
        frontNodePtr = newNodePtr;
        printf("%d is enqued in the queue.\n", value); 
    }
}


int main()
{
    enqueu(1); 
    enqueu(2);

    printQueue(); 

    return 0; 
}
