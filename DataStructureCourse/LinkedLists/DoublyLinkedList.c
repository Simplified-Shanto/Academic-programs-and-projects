#include<stdio.h> 
#include<stdlib.h> 


typedef struct Node{
    int data;
    struct Node *prevNodePtr;
    struct Node *nextNodePtr; 
} Node; 


Node* createNodePtr(int data)
{
    Node* newNodePtr = malloc(sizeof(Node));
    newNodePtr->data = data;
    newNodePtr->prevNodePtr = NULL;
    newNodePtr->nextNodePtr = NULL; 
}

void printNodeListForward(Node* startingNodePtr)
{
   // Node *tempNodePtr = startingNodePtr; 
    while(startingNodePtr!=NULL)
    {
        printf("Data = %d\n", startingNodePtr->data);
        startingNodePtr = startingNodePtr->nextNodePtr; 
       
    }
}


void printNodeListBackward(Node* endNodePtr)
{
    while(endNodePtr!=NULL)
    {
        printf("Data = %d\n", endNodePtr->data);
        endNodePtr = endNodePtr->prevNodePtr; 
    }
}


Node* insertElement(Node* firstNodePtr, int data, int index) // This function will return the new first node pointer 
{
    Node* newNodePtr = createNodePtr(data); 
    if(index==0) { // We want to repalce the very first element with the new element.
        newNodePtr->nextNodePtr = firstNodePtr;
        firstNodePtr->prevNodePtr = newNodePtr;
        printf("%d inserted at the very beginning. \n", data); 
        return newNodePtr; 
    }
    else 
    {
        Node *currentNodePtr = firstNodePtr; 
        //Traverse to the element after which we want to insert the element.
        for (int i = 2; i < index; i ++ )
        {
            currentNodePtr = currentNodePtr->nextNodePtr;
          //  printf("Reached %d th element\n", i); 
        }

        //Case1 :there are n elements, we want to insert an element in the n + 1 th position of the list.
        if(currentNodePtr->nextNodePtr==NULL)  // We are currently at the last node. 
        {
            newNodePtr->prevNodePtr = currentNodePtr;
            currentNodePtr->nextNodePtr = newNodePtr;
            printf("%d inserted at the end of the list\n", data); 
            return firstNodePtr; 
        }
        else     //Case 2: We'll insert somewhere in the  middle of the list . 
        {
            Node *rightNodePtr = currentNodePtr->nextNodePtr;
            newNodePtr->nextNodePtr = rightNodePtr;
            currentNodePtr->nextNodePtr = newNodePtr;
            rightNodePtr->prevNodePtr = newNodePtr;
            printf("%d inserted at position %d\n", data, index); 
        }
    
    }

    
}



int main()
{
    Node *nodeAptr = createNodePtr(1);
    Node *nodeBptr = createNodePtr(2);
    Node *nodeCptr = createNodePtr(3);
    Node *nodeDptr = createNodePtr(4);

    printf("Nodes created successfully!\n"); 
    
    //Forward linking 

    nodeAptr->nextNodePtr = nodeBptr;
    nodeBptr->nextNodePtr = nodeCptr;
    nodeCptr->nextNodePtr = nodeDptr; 
   // nodeDptr->nextNodePtr = 


    //Backward linking 
    nodeDptr->prevNodePtr = nodeCptr;
    nodeCptr->prevNodePtr = nodeBptr;
    nodeBptr->prevNodePtr = nodeAptr;

    nodeAptr = insertElement(nodeAptr, 5, 0);
    nodeAptr = insertElement(nodeAptr, 6, 0);
    nodeAptr = insertElement(nodeAptr, 7, 7); 
    printNodeListForward(nodeAptr);
    nodeAptr = insertElement(nodeAptr, 111, 3); 
    printNodeListForward(nodeAptr);

    printf("Forward direction traversal: \n"); 
    printNodeListForward(nodeAptr); 



    printf("Backward direction traversal: \n"); 
    printNodeListBackward(nodeDptr);

    return 0; 
}