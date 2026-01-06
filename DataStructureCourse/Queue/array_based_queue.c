#include<stdio.h> 
#define CAPACITY 100

int QUEUE[CAPACITY];  //Since global, it's initialized with zeros. 
int FRONT = -1; 
int REAR = -1; 



void printQueue()
{
    printf("\nThe queue currently looks like this: \n"); 
    for (int i = FRONT; i <= REAR; i++)
    {
        printf("%d\n", QUEUE[i]); 
    }
}


void insert(int value)
{
    if (FRONT == -1) // There's currently no element in the queue
    {
        FRONT = REAR = 0; // FRONT and REAR  are basically indices of the array.
        QUEUE[REAR] = value; // Adding the new element at the very back of the queue
        printf("Inserted Element: %d\n", value); 
    }
    else if(REAR+1<CAPACITY)
    {
        REAR++;
        QUEUE[REAR] = value;
        printf("Inserted Element: %d\n", value); 
    }
    else printf("Queue is Full!\n"); 
}


void delete()
{
    if(FRONT==-1 && REAR==-1)
    {
        printf("\nNothing to delete! Queue is already empty\n"); 
    }
    else if(FRONT==REAR) //There's only one element in the queue,  The queue becomes empty after deleting this element. 
    {
        FRONT = -1;
        REAR = -1; 
    }
    else //,  The queue is not empty after deleting this element. 
    {
        printf("\n%d is deleted from the queue\n", QUEUE[FRONT]); 
        FRONT++; 
    }
}






int main()
{
    insert(1);
    insert(2);
    insert(3); 

    printQueue(); 

    delete();

    printQueue(); 

    return 0; 
}