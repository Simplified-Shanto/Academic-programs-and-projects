// Usage of the storage class static.

// Compile both files together with: gcc file1.c file2.c -o combinedProgram
// Run the .exe file:   .\combinedProgram    or .\combinedProgram.exe

#include <stdio.h>

extern int neighbour; // No memory is allocated here.

void printNumber()
{
    static int num = 0; // The num integer is not recreated, but the previous declaration and the value is used in each function call.
    num++;
    printf("Num = %d\n", num);
}

int main()
{
    printNumber();
    printNumber();
    printf("Neighbour = %d", neighbour);

    return 0;
}