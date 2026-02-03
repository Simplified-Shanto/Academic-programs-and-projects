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
    printf("List (forward): \n"); 
    while(startingNodePtr!=NULL)
    {
        printf("Data = %d\n", startingNodePtr->data);
        startingNodePtr = startingNodePtr->nextNodePtr; 
    }
}

void printNodeListBackward(Node* endNodePtr)
{
    printf("List (backward): \n"); 
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
        if(firstNodePtr==NULL) // We are inserting element to an empty list. 
        {
            printf("Initialized the first node of the empty list!\n"); 
            return newNodePtr;   
        }
        else  // We are inserting at the very beginning of a non-empty list 
        {
            newNodePtr->nextNodePtr = firstNodePtr;
            firstNodePtr->prevNodePtr = newNodePtr;
            printf("%d inserted at the very beginning. \n", data);
            return newNodePtr; 
        }

       
       
    }
    else 
    {
        Node *currentNodePtr = firstNodePtr; 
        //Traverse to the element after which we want to insert the element.
        for (int i = 1; i < index; i ++ )
        {
            if(currentNodePtr->nextNodePtr==NULL) // There are n nodes, but user wants to insert at the n + 2 or greater index 
            {
                printf("\nThere's %d nodes, can't insert node at index %d\n", i + 1, index); 
                return firstNodePtr; 
            }
             // Keep traversing till the asked index is reached. 
             // printf("Reached %d th element\n", i); 
                currentNodePtr = currentNodePtr->nextNodePtr;
        }

        //Case1 :there are n elements, we want to insert an element in the n + 1 th position of the list.
        if(currentNodePtr->nextNodePtr==NULL)  // We are currently at the last node. 
        {
            newNodePtr->prevNodePtr = currentNodePtr;
            currentNodePtr->nextNodePtr = newNodePtr;
            printf("%d inserted at the end of the list\n", data); 
            return firstNodePtr; 
        }
        else     //Case 2: We'll insert somewhere in between two existing element of the list . 
        {
            Node *rightNodePtr = currentNodePtr->nextNodePtr;
            newNodePtr->nextNodePtr = rightNodePtr; // Forward linking of the new node 
            rightNodePtr->prevNodePtr = newNodePtr; // Backward linking of the right node 
            currentNodePtr->nextNodePtr = newNodePtr;// Forward linking of the left node
            newNodePtr->prevNodePtr = currentNodePtr; // Backward linking of the new node

            printf("%d inserted at position %d\n", data, index); 
        }
        return firstNodePtr; 
    }

    
}

 Node *headNodePtr; // This headnodePtr is null since declared in the global scope. 

int main()
{
   
    insertElement(headNodePtr, 10, 0);
    if(headNodePtr==NULL)

    insertElement(headNodePtr, 11, 1);
  //  insertElement(headNodePtr, 12, 4); 

    //     printf("\nNodes created successfully!\n");

    //     //Forward linking

    //     nodeAptr->nextNodePtr = nodeBptr;
    //     nodeBptr->nextNodePtr = nodeCptr;
    //     nodeCptr->nextNodePtr = nodeDptr;

    //     printf("\nForward linking is done!\n");

    //     //Backward linking
    //     nodeDptr->prevNodePtr = nodeCptr;
    //     nodeCptr->prevNodePtr = nodeBptr;
    //     nodeBptr->prevNodePtr = nodeAptr;

    //     printf("\nBackward linking is done!\n");

    //     nodeAptr = insertElement(nodeAptr, 5, 0);  // Test of insertion at the very beginning
    //     nodeAptr = insertElement(nodeAptr, 6, 0);
    //     nodeAptr = insertElement(nodeAptr, 7, 6);  // Test of insertion at the very end of the list

    //     printNodeListForward(nodeAptr);

    //     nodeAptr = insertElement(nodeAptr, 111, 3); // Test of insertion inbetween two existing node in the list

    //     printNodeListForward(nodeAptr);
    //    // printNodeListBackward(nodeDptr);

    return 0; 
}