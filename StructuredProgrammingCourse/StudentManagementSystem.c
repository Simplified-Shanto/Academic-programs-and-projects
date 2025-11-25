#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Number of students: ");
    scanf("%d", &n);

    // clear newline after scanf("%d")
    getchar();

    FILE *fptr = fopen("input.txt", "w");

    for (int i = 0; i < n; i++)
    {
        char name[50];
        int ID;
        float CG;
        int mark_phy, mark_chem, mark_math;

        printf("Name: ");
        fgets(name, sizeof(name), stdin);

        printf("ID: ");
        scanf(" %d", &ID);

        printf("CG: ");
        scanf(" %f", &CG);

        printf("Phy_mark Chem_mark Math_mark: ");
        scanf(" %d %d %d", &mark_phy, &mark_chem, &mark_math);

        fprintf(fptr, "%s", name);
        fprintf(fptr, "%d\n", ID);
        fprintf(fptr, "%f\n", CG);
        fprintf(fptr, "%d\n", mark_phy);
        fprintf(fptr, "%d\n", mark_chem);
        fprintf(fptr, "%d\n", mark_math);
        fprintf(fptr, "--------------------------\n");
    }
    fclose(fptr); // Closing the file which was opened in writing mode.

    fptr = fopen("input.txt", "r");                     // Reopening the file in reading mode.
    FILE *outputFilePointer = fopen("output.txt", "w"); // We'll write the final parameters and Grades in this file.
    char fileContent[100];                              // String that will contain the newline readings from the inputfile.txt
    for (int i = 0; i < n; i++)
    {
        float sum = 0;
        for (int j = 0; j < 6; j++) // Here 6 is the total number of parameters we saved for a person.
        {
            fgets(fileContent, 100, fptr);
            fprintf(outputFilePointer, fileContent);
            if (j > 2)
            {
                int num = atoi(fileContent); // Convert string to integer for addition.
                sum += num; 
                printf("%d\n", atoi(fileContent)); 
            }
        }
        printf("sum = %d\n",  sum); 
        fprintf(outputFilePointer, "Grade: "); 
        fprintf(outputFilePointer, "%f\n", sum); 
    }

    fclose(outputFilePointer); 

    return 0;
}
