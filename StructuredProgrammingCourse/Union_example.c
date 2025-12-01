#include <stdio.h>

union Data
{
    int i;
    float f;
    char c;
};

int main()
{
    union Data myData; // Declare a union variable

    myData.i = 10;
    printf("Integer: %d\n", myData.i);

    myData.f = 20.5f; // Assigning to 'f' overwrites 'i'
    printf("Float: %.2f\n", myData.f);

    myData.c = 'A'; // Assigning to 'c' overwrites 'f'
    printf("Character: %c\n", myData.c);

    // Note: Trying to access 'i' or 'f' after assigning to 'c' would result in garbage values
    // as they share the same memory location.
    printf("Integer (after char assignment): %d\n", myData.i);

    return 0;
}