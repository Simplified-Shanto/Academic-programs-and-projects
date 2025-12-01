#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number of student: ");
    int n;
    scanf("%d", &n);
    getchar(); // Clearing input buffer.

    FILE *inputFilePointer = fopen("input.txt", "w");

    for (int i = 0; i < n; i++) // Input taking and writing to file loop.
    {
        printf("Name: ");
        char name[100];
        fgets(name, sizeof(name), stdin);
        fprintf(inputFilePointer, name);

        printf("ID: ");
        int ID;
        scanf("%d", &ID);
        fprintf(inputFilePointer, "%d\n", ID);

        printf("CG: ");
        float CG;
        scanf("%f", &CG);
        fprintf(inputFilePointer, "%d\n", CG);

        printf("Math_mark Phy_mark Chem_mark: ");
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        fprintf(inputFilePointer, "%d\n", a);
        fprintf(inputFilePointer, "%d\n", b);
        fprintf(inputFilePointer, "%d\n", d);

        char c;
        while ((c = getchar()) != '\n' && c != EOF)
            ; // Cleaning infput buffer.
    }
    fclose(inputFilePointer);

    FILE *sourceFilePointer = fopen("input.txt", "r");  // Reopening the file in reading mode.
    FILE *outputFilePointer = fopen("output.txt", "w"); // We'll write the final parameters and Grades in this file.

    for (int i = 0; i < n; i++)
    {
        float sum = 0.0f;

        char name[100]; // String that will contain the newline readings from the inputfile.txt
        // read name line
        if (fgets(name, sizeof(name), inputFilePointer) == NULL)
        {
            printf("Error reading name for person %d", i + 1);
            break;
        }
        // write name safely
        fprintf(outputFilePointer, "%s", name);

        // read ID line (it was written as "%d\n")
        int ID;
        if (fscanf(inputFilePointer, "%d\n", &ID) != 1)
        {
            printf("Error reading ID for person %d", i + 1);
            break;
        }
        // Write Id
        fprintf(outputFilePointer, "%d\n", ID);

        // read CG line
        float CG;
        if (fscanf(inputFilePointer, "%f\n", &CG) != 1)
        {
            printf("Error reading CG for person %d", i + 1);
            break;
        }
        fprintf(outputFilePointer, "%f\n", CG);

        // read three marks
        int mark_phy, mark_chem, mark_math;
        if (fscanf(inputFilePointer, "%d\n%d\n%d\n", &mark_phy, &mark_chem, &mark_math) != 3)
            break;
        fprintf(outputFilePointer, "%d\n%d\n%d\n", mark_phy, mark_chem, mark_math);

        sum = mark_phy + mark_chem + mark_math;
        fprintf(outputFilePointer, "Total mark: %f\n", sum);
    }
    fclose(inputFilePointer);
    fclose(outputFilePointer);

    return 0;
}
