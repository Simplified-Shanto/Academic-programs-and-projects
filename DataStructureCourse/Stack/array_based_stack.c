#include<stdio.h>

int max_size = 10; 
int STACK[max_size]; 

void top()
{
    if(SP_TOP>=0)
        printf("Top Element: %d\n", STACK[SP_TOP]); 
    else
        printf("Empty Stack!\n"); 
}


void print()
{
    printf("---Stack Top>\n");
    for (int i = SP_TOP; i >= 0; i--)
        printf()
}

void pop()
{
    if(SP_TOP>=0)
    {
        printf("Popped Element: %d\n", STACK[SP_TOP]); 
    }
    else
        printf("Empty Stack!\n"); 
}

int main()
{

}