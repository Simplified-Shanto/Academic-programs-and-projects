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
    newNode = malloc(sizeof(newNode));
    newNode->data = value;
    newNode->next = NULL; 
}

void printList(Node *startingNode)
{
    while(startingNode!=NULL)
    {
        printf("%d ", startingNode->data);
        startingNode = startingNode->next; 
        
    }
    printf("\n"); 
}

// Appending element at a particular index of the linked list. 

Node* insertNode(Node* leftMostNodePointer, int index, int value)
{
    Node *newNodePointer = createNode(value); 
    if(index==0)
    {
        newNodePointer->next = leftMostNodePointer;
        return newNodePointer; 
    }
    else 
    {
        Node *currentNodePointer = leftMostNodePointer;
        for (int i = 1; i < index; i++) // Traversing the entire list to reach the node after which we'll insert the new node. 
        {
            currentNodePointer = currentNodePointer->next; 
        }
        
        if(currentNodePointer->next == NULL) // There are n nodes in the list, but we want to insert the node at n+1 th position. 
        {
            currentNodePointer->next = newNodePointer;
            
        }
        else
        {
        Node *temporaryNodePointer = leftMostNodePointer->next;
        leftMostNodePointer->next = newNodePointer;
        newNodePointer->next = temporaryNodePointer;
        }

        return leftMostNodePointer; 
    }
    
}



int main()
{
    Node *head = createNode(1);
    head = insertNode(head, 1, 0);
        printList(head); 
    head = insertNode(head, 1, 2);
        printList(head); 
    head = insertNode(head, 1, 3); 
        printList(head); 
    head = insertNode(head, 1, 3); 
        printList(head);
    head = insertNode(head, 2, 4); 
        printList(head); 
    head = insertNode(head, 6, 6); 
        printList(head); 
}















// // Implement a programme to add a new element at any index of a linked list.
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node
// {
//     int data;
//     struct Node *next;
// } Node;

// Node *createNode(int value)
// {
//     Node *newNode;
//     newNode = malloc(sizeof(newNode));
//     newNode->data = value;
//     newNode->next = NULL;

//     return newNode;
// }

// void printList(Node *startingNode)
// {
//     while (startingNode != NULL)
//     {
//         printf("%d ", startingNode->data);
//         startingNode = startingNode->next;
//     }
//     printf("\n");
// }

// // Say, we want to insert a node at the 5 th index (starting from 0), then the element in the index 5 will have index 6 after the addition.
// Node *addNode(Node *currentFirstNodePointer, int index, int value) // This function will return the memory address of the first node after addition of the new node.
// {
//     Node *newNodePointer = createNode(value);

//     if (index == 0)
//     {
//         newNodePointer->next = currentFirstNodePointer;
//         return newNodePointer;
//     }
//     else
//     {
//         Node *currentNodePointer = currentFirstNodePointer;  // We won't change the currentFirstNodePointer because, we'll have to return it after the execution of this part. 
//         for (int i = 1; i < index; i++) // Traversing until the insertion node.
//         {
//             currentNodePointer = currentNodePointer->next;
//         }

//         if (currentNodePointer->next == NULL) // Max index is n, but we want to add element at n + 1 th index.
//         {
//             currentNodePointer->next = newNodePointer;
//             return currentFirstNodePointer;
//         }
//         else
//         {
//             Node *rightNodePointer = currentNodePointer->next;
//             currentNodePointer->next = newNodePointer;
//             newNodePointer->next = rightNodePointer;
//             return currentFirstNodePointer;
//         }
//     }
// }

// int main()
// {
//     Node *leftMostNode = createNode(1);
//     printList(leftMostNode);

//     leftMostNode = addNode(leftMostNode, 0, -1);
//     printList(leftMostNode);

//     leftMostNode = addNode(leftMostNode, 0, -2);
//     printList(leftMostNode);

//     leftMostNode = addNode(leftMostNode, 0, -3);
//     printList(leftMostNode);

//     leftMostNode = addNode(leftMostNode, 3, -4);
//     printList(leftMostNode);

//     leftMostNode = addNode(leftMostNode, 3, -5);
//     printList(leftMostNode);

//     leftMostNode = addNode(leftMostNode, 5, -6);
//     printList(leftMostNode);

//     leftMostNode = addNode(leftMostNode, 6, -7);
//     printList(leftMostNode);

//     return 0;
// }



// #include<stdio.h>
// #include<stdlib.h>

// typedef struct Node
// {
//     int data;
//     struct Node *next;
// } Node;

// Node* createNode(int value)
// {
//     Node *node; //Creating a node pointer.
//     node = malloc(sizeof(node));
//     node->data = value;
//     node->next = NULL;

//     return node;
// }

// void printList(Node* startingNodePointer)
// {
//     while(startingNodePointer!=NULL)
//     {
//         printf("%d ", startingNodePointer->data);
//         startingNodePointer = startingNodePointer->next;
//     }
//     printf("\n");
// }

// void freeMemory(Node* startingNodePointer)
// {
//     while(startingNodePointer!=NULL)
//     {
//         Node *temp = startingNodePointer->next;
//         free(startingNodePointer);
//         startingNodePointer = temp;
//     }
// }

// //Modify this program to add incoming nodes at the end of the list and print the updated list each time.

// int main()
// {
//     int a;
//     scanf("%d", &a);
//     Node *leftMostNode = createNode(a);
//     printList(leftMostNode);
//     Node *rightMostNode = leftMostNode;
//     Node *newNode;

//     while(1)
//     {
//         scanf("%d", &a);
//         newNode = createNode(a);
//         if(a==0)
//         {
//             break;
//         }
//         else if(a >= 0)  // If the number is non-negative append it to the right side of the list.
//         {
//             rightMostNode->next = newNode; // Changing the pointer of the rightMostNode from NULL to the newly added node's memory address.
//             rightMostNode = newNode; // Now rightMostNode points to the newly created node and it's next attribute = NULL
//         }
//         else  //Otherwise append it to the left side of the list.
//         {
//             newNode->next = leftMostNode; // We want to place the newnode at the very beginning of the list, so it'll point to the current first node of the list
//             leftMostNode = newNode; // New leftMostNode should contain the memory address of the new first node.
//         }

//         printList(leftMostNode);
//     }
//     freeMemory(leftMostNode);

//     return 0;
// }

// Implement Linked List with Structure - Standardized approach.

// #include<stdio.h>
// #include<stdlib.h>

// typedef struct Node{
//     int data;
//     struct Node *next; // This will save the pointer to the next node, not only the value in that node.
// } Node;

// Node* createNode(int value)
// {
//     Node *newNode = malloc(sizeof(Node)); // Creating a node pointer and allocating memory to that.
//     newNode->data = value;
//     newNode->next = NULL;

//     return newNode;
// }

// void printList(Node* node)  // This will print the list given the starting node pointer.
// {
//     while(node!=NULL)
//     {
//         printf("%d ", node->data);
//         node = node->next;
//     }
// }

// int main()
// {
//     Node* node1 = createNode(1);
//     Node* node2 = createNode(2);
//     Node* node3 = createNode(3);
//     Node *node4 = createNode(4);

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node4;

//     printList(node1);

//     free(node1);
//     free(node2);
//     free(node3);
//     free(node4);

//     return 0;
// }

// // Implement linked list with structure - My initial - get your hands dirty attempt

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// int counter = 1;

// int main()
// {
//     struct node FirstElement = {1, NULL};
//     struct node LastElement = {0, NULL};

//     while (counter)
//     {
//         printf("Input a number to add at the beginning of the linked list: \n");
//         int inp;
//         scanf("%d", &inp);
//         struct node *new = malloc(sizeof(struct node));
//         new->data = inp;
//         new->next = NULL;
//         FirstElement.next = new;
//         int temp = FirstElement.data;
//         FirstElement.data = new->data;
//         new->data = temp;

//         counter++;
//         printf("The list now looks like: \n");
//         printf("%d \n", FirstElement.data);
//         struct node *currentNode = FirstElement.next;
//         printf("%d \n", currentNode->data);

//         while (currentNode != NULL)
//         {
//             printf("%d\n", currentNode->data);
//             currentNode = currentNode->next;
//         }
//     }

//     return 0;
// }

// Write a demonstration of pass by value and pass by reference for structure.

// #include<stdio.h>

// struct student{
//     int age;
//     int id;
//     char *name;
// };

// void displayData(struct student sA)  // Pass by value
// {
//     printf("Name: %s\nAge: %d\nID: %d\n\n", sA.name, sA.age, sA.id);
// }

// void changeAge(struct student *sA, int newAge) //Pass by reference
// {
//     sA->age = newAge;
// }

// int main()
// {
//     struct student studentA = {13, 2024001, "Shimanto"};

//     displayData(studentA);
//     changeAge(&studentA, 20);
//     displayData(studentA);

//     return 0;
// }

// For 5 students, create a struct, that will store their reg, course code, marks gpa (determine it from the marks )

// Use nested structure to include the date of birth of the student.

// Change the value of an element to a structure by passing it to a function. Print the previous and the current value using the pointer.
// Create an array of stucture, populate, and print

// #include<stdio.h>

// struct student{
//     char *name;
//     int age;
//     int id;
// };

// void changeAge(struct student *learner)
// {
//     learner->age = (learner->age) * 2;
// }

// int main()
// {
//     struct student student1;
//     student1.name = "shanto";
//     student1.age = 22;
//     student1.id = 360;

//     printf("Student %s 's current age is %d\n", student1.name, student1.age);
//     struct student *pointer = &student1;
//     changeAge(pointer);

//     printf("Student %s 's age after passing is %d\n", pointer->name, pointer->age);

//     struct student students[3];
//     for (int i = 0; i < 3; i++)
//     {
//         students[i].name = "kung fu";
//         students[i].age = i * 30;
//         students[i].id = 111 * i;
//     }

//     for (int j = 0; j < 3; j++)
//     {
//         printf("Student: %s \n Age: %d \n ID: %d\n\n", students[j].name, students[j].age, students[j].id);
//     }
//         return 0;
// }