#include<stdio.h> 
#include<stdlib.h> 


typedef struct bst_node
{
    int info; 
    struct bst_node *LEFT, *RIGHT;
} NODE; 

NODE* insert(NODE* ROOT, int value)
{
    if(ROOT==NULL)
    {
        NODE *new_node = (NODE*)malloc(sizeof(NODE));
        new_node->info = value;
        new_node->LEFT = new_node->RIGHT = NULL;
        ROOT = new_node;
        printf("%d Inserted!\n", value); 
    }
    else if(value < ROOT->info)
    {
        ROOT->LEFT = insert(ROOT->LEFT, value); 
    }
    else if(value >= ROOT->info)
        ROOT->RIGHT = insert(ROOT->RIGHT, value);

    return ROOT; 
}


void search(NODE* ROOT, int value)
{
    if(ROOT==NULL)
        printf("%d not present in the tree!!\n", value); 
    else if(value==ROOT->info)
        printf("Element %d is present in the tree!!\n", value); 
    else if(value<ROOT->info)
        search(ROOT->LEFT, value); 
    else
        search(ROOT->RIGHT, value); 
}

void display(NODE *ROOT)
{
    if(ROOT==NULL)
    {
        printf("Tree root is NULL\n");
        return; 
    }
    if(ROOT->LEFT!=NULL)
        display(ROOT->LEFT);

    printf("%d ", ROOT->info); 

    if(ROOT->RIGHT!=NULL)
        display(ROOT->RIGHT); 
}


int main()
{
    NODE* root = NULL;
    root   = insert(root, 35);

    insert(root, 22);
    insert(root, 64);
    insert(root, 15); 
    insert(root, 42);
    insert(root, 77);
    insert(root, 18);
    insert(root, 39);

    display(root); 

    return 0; 
}