#include<stdio.h> 
#include<stdlib.h> 

// the left and right child node of a vertex has to be specified 

#define V 10 // Total number of vertices in the tree. 

typedef struct Node
{
    int key;
    struct Node *leftChild;
    struct Node *rightChild; 
} Node;


Node* createNode(int data )
{
    Node *newNodePtr = malloc(sizeof(Node));
    newNodePtr->key = data; 
    newNodePtr->leftChild   = NULL;
    newNodePtr->rightChild = NULL; 
}


void postOrderTraversal(Node* root)
{
    if(root == NULL)
        return;

    postOrderTraversal(root->leftChild);
    postOrderTraversal(root->rightChild); 
    printf("%d -> ", root->key); // Visited node.
}


int main()
{
    Node *root = createNode(100);
    root->leftChild = createNode(200);
    root->rightChild = createNode(50);

    root->leftChild->rightChild = createNode(100);
    root->leftChild->leftChild = createNode(400);

    root->rightChild->rightChild = createNode(300);
    root->rightChild->leftChild = createNode(150);

    postOrderTraversal(root); 
}

