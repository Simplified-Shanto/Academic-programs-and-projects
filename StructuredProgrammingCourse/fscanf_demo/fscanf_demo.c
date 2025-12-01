#include <stdio.h> 
#include <stdlib.h> 

int main()
{
    FILE *fptr = fopen("input.txt", "r");
    int a, b, c;
    fscanf(fptr, "%d%d%d", &a, &b, &c);
    printf("%d %d %d\n", a, b, c);
    fclose(fptr); 
    return 0; 
}