#include<stdio.h> 

int main()
{
    FILE *fptr;

    fptr = fopen("filename.txt", "w");

    // Check if the file was created successfully
    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        return 1; 
    }

    fclose(fptr); 
    return 0;
}