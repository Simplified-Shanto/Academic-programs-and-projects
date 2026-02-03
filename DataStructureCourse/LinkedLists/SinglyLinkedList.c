#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node
{
    int data;
    struct Node *next;
} Node; 

Node* createNode(int value)
{
    Node *newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL; 
    return newNode; 
}

void printList(Node *startingNode)
{
    if(startingNode==NULL)
    {
        printf("List is empty! Nothing to print\n"); 
    }

    while(startingNode!=NULL)
    {
        printf("%d ", startingNode->data);
        startingNode = startingNode->next; 
        
    }
    printf("\n"); 
}


//Appending element at a particular index of the linked list. 

Node* insertNode(Node* leftMostNodePointer, int index, int value)  // This function returns the new leftmost node in the linked list after performing the insertion. 
{
    Node *newNodePointer = createNode(value); 
    if(index==0) //Inserting element in the very first element of the list. 
    {
        if(leftMostNodePointer==NULL) // Inserting element in an empty list 
        {
            printf("Initialized the first node of the empty list!\n");
            return newNodePointer; 
        }
        
        newNodePointer->next = leftMostNodePointer;
        printf("%d inserted at the very beginning. \n", value);
        return newNodePointer;   // The element just inserted, is now the leftmost element in the linked list 
    }
    else 
    {
        Node *currentNodePointer = leftMostNodePointer;
        for (int i = 1; i < index; i++) // Traversing the entire list to reach the node after which we'll insert the new node. 
        {
            if(currentNodePointer->next==NULL) // There are n nodes, but user wants to insert at the n + 2 or greater index 
            {
                printf("\nThere's %d nodes, can't insert node at index %d\n", i + 1, index); 
                return leftMostNodePointer; 
            }
            currentNodePointer = currentNodePointer->next; 
        }
        
        if(currentNodePointer->next == NULL) // There are n nodes in the list, but we want to insert the node at n+1 th position. 
        {
            currentNodePointer->next = newNodePointer;
        }
        else  // We want to insert the element in a non terminal position in the linked list. 
        {
        Node *temporaryNodePointer = currentNodePointer->next; // Storing the pointer to the rightNode before which the newNode will be inserted. 
        currentNodePointer->next = newNodePointer;
        newNodePointer->next = temporaryNodePointer;
        }
        return leftMostNodePointer; 
    }
}



void searchNode(Node* startingNodePtr, int value)
{
    if(startingNodePtr==NULL)
    {
        printf("List is empty! Nothing to search\n"); 
        return; 
    }

    Node *currentNodePtr = startingNodePtr; 
    while(currentNodePtr!=NULL)
    {
        if(currentNodePtr->data == value)
        {
            printf("%d is found in the list\n", value);
            return; 
        }
        currentNodePtr = currentNodePtr->next; 
    }
    printf("%d is not found in the list\n", value);
}

Node* deleteNode(Node* startingNodePointer, int value)  // This function will return the new startingNodePointer after the deletion operation 
{
    if(startingNodePointer==NULL)  // Attempt to delete an element from an empty list 
    {
        printf("List is already empty! Nothing to delete.\n");
        return NULL; 
    }

    // If the starting node Pointer has to be deleted 
    if(startingNodePointer->data==value)
    {
        Node* newFirstNodePtr = startingNodePointer->next; 
        free(startingNodePointer); 
        return newFirstNodePtr; 
    }
    
    
    Node* currentNodePtr = startingNodePointer; 
    Node* previousNodePtr; 
    while(currentNodePtr!=NULL && currentNodePtr->data!=value)
    {
        previousNodePtr = currentNodePtr; // Storing the previous node of the deletable node for the linking opeartions later. 
        currentNodePtr = currentNodePtr->next;
    }
  
    if(currentNodePtr==NULL) // No such value is found in the list, so it ended up to be a null pointer. 
    { 
        printf("No value %d is found in the list! Unable to delete !\n", value); 
        return startingNodePointer; 
    }

    if(currentNodePtr->next==NULL) // Deletable node is the last node here 
    {
        previousNodePtr->next = NULL; 
        free(currentNodePtr); 
        return startingNodePointer; 
    }

    // Deletable node has both left and right node surrounding it.
    previousNodePtr->next = currentNodePtr->next;
    free(currentNodePtr);
    return startingNodePointer; 
}



void freeMemory(Node* startingNodePointer)
{
    while(startingNodePointer!=NULL)
    {
        Node *temp = startingNodePointer->next;
        free(startingNodePointer);
        startingNodePointer = temp;
    }
}



int main()
{
    Node *head = createNode(1);
    insertNode(head, 1, 11);
    printList(head); 
    head =  deleteNode(head, 11);
    printList(head);
    insertNode(head, 1, 12);
    insertNode(head, 2, 13);
    insertNode(head, 3, 14);
    insertNode(head, 4, 15);


    searchNode(head, 8); 


    printList(head);
    deleteNode(head, 13);
    printList(head); 

    return 0; 
}
















