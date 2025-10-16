#include <stdio.h>

int main()
{
    char str[200] = "Sea me we 4";
    for (char *charPointer = str; *charPointer != '\0'; charPointer++)
    {
        printf("%c", *charPointer);
    }
    return 0;
}