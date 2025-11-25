#include <stdio.h> 
#include <stdlib.h> 


// Objective: find the sum of all integers in a string. 
// Stragey: Start traversing the string right to left. 

int main()
{
    FILE *fptr = fopen("input.txt", "r");
    int a, b, c, d, e; 
    int sum = 0;
    fscanf(fptr, "%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("%d\n", a); 
    return 0; 
}