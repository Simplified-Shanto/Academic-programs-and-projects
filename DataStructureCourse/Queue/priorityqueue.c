#include<stdio.h> 
#include<stdlib.h> 


typedef struct node 
{
    int INFO;
    int PRIORITY;
    struct node *NEXT;
} NODE;

NODE *FRONT;  // Front is initialized to NULl since declared in the global scope.

void insert(int value, int p )
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    new_node->INFO = value;
    new_node->PRIORITY = p;
    new_node->NEXT = NULL; 

    /*Checking if the newly allocated queue element needs to be inserted at the front*/

    if (FRONT == NULL || new_node->PRIORITY < FRONT->PRIORITY)  // Element with the least priority will be the FRONT element. 
    {
        new_node->NEXT = FRONT;
        FRONT = new_node; 
    }
    else 
    {
        NODE *curr_ptr = FRONT; 
        //At this point our queue is sorted according to the priority of the elements, And we'll insert the new element in this priority-sorted list according to its priority. 
        while(curr_ptr->NEXT!=NULL && curr_ptr->NEXT->PRIORITY <= new_node->PRIORITY)
            curr_ptr = curr_ptr->NEXT;

        new_node->NEXT = curr_ptr->NEXT;
        curr_ptr->NEXT = new_node; 
    }

    if(new_node!=NULL)
        printf("Inserted Element\n");
}



void print()
{
    printf("Queue Front: < | ");
    NODE *curr_ptr = FRONT; 
    
    while(curr_ptr!=NULL)
    {
        printf("%d", curr_ptr->INFO);
        printf("(%d) ", curr_ptr->PRIORITY); 
        curr_ptr = curr_ptr->NEXT; 
    }

    printf("|>: Queue Rear\n"); 
}





void delete()
{
    if(FRONT==NULL)
        printf("Empty Queue!\n"); 
    else 
    {
        NODE *ptr = FRONT->NEXT; //Front is our element with the top most priority, so it should be deleted first of all. 
        printf("Deleted Element: %d\n", FRONT->INFO);
        free(FRONT);
        FRONT = ptr; 
    }
}


void front()
{
    if(FRONT==NULL)
        printf("Empty Queue!\n"); 
    else 
        printf("Front Element: %d\n", FRONT->INFO); 

}


void rear()
{
    if(FRONT== NULL)
    {
        printf("Empty Queue!\n"); 
    }
    else 
    {
        NODE *curr_ptr = FRONT; 
        while(curr_ptr->NEXT!=NULL)
        {
            curr_ptr = curr_ptr->NEXT; 
        }

        printf("Rear Element: %d\n", curr_ptr->INFO); 
    }
}


int main()
{
    insert(60, 6);
    insert(80, 8);
    insert(100, 10); 


    insert(10, 1);
    insert(20, 2);
    insert(30, 3);
    insert(50, 5);

    front(); 

    print();

    delete();

    print();
    delete();
    print();

    rear(); 

    return 0; 
}