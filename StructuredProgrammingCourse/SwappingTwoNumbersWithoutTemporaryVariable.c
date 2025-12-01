#include<stdio.h> 


// Using arithmetic operation

int main()
{
    unsigned int a,  b;
    scanf("%u %u", &a, &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %X, b = %u", a, b); 

    return 0; 
}