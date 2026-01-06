#include<stdio.h> 
#include<stdlib.h> 

typedef struct Node 
{
    int data;
    struct Node *Next;
} Node;

Node *TopNodePtr; //Since declared in global scope, it's set to NULL initially. 


void printStack()
{
    Node *tempNodePtr = TopNodePtr;

    printf("\nCurrently the stack looks like this: \n"); 
    while(tempNodePtr!=NULL)
    {
        printf("%d\n", tempNodePtr->data);
        tempNodePtr = tempNodePtr->Next; 
    }
}


void push(int value)
{
    Node *new_node_ptr = (Node*)malloc(sizeof(Node));
    new_node_ptr->data = value;
    new_node_ptr->Next = NULL; 

    if(TopNodePtr==NULL) // The stack is currently empty and we are entering the very first node in the empty stack. 
    {
        TopNodePtr = new_node_ptr;
        printf("%d is entered as the bottom element of the stack\n", value); 
    }
    else  // The stack is not empty. 
    {
        new_node_ptr->Next = TopNodePtr;  //Think of Next as Prev here, because, the top element is pointing to the element just below it in the stack. 
        //At this point our new_node_ptr holds the correct link with the previous element in the stack. 
        //But the global variable TopNodePtr is supposed to hold the top most element in the stack. 
        TopNodePtr = new_node_ptr;  
        //At this point TopNodePtr holds the latest entry as its data and pointer to the previous top node pointer as its Next element. 
        //We need only this TopNodePtr to traverse through the entire stack.
        printf("%d is entered in the non empty stack\n", value); 
    }
}


void pop()
{
    if(TopNodePtr==NULL)
    {
        printf("\nStack is already empty! Stack Underflow!\n"); 
    }
    else 
    {
        Node *ToBeDeletedNodePtr = TopNodePtr; // Storing the current TopNodePtr for freeing its memory. 
        TopNodePtr = TopNodePtr->Next;
        printf("%d is removed from the stack", ToBeDeletedNodePtr->data); 
        free(ToBeDeletedNodePtr); 
    }

}



int main()
{
    push(1);
    push(2);
    push(3);
    push(4); 

    printStack();

    pop();

    printStack(); 

    return 0; 
}

