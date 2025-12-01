#include<stdio.h> 

int main()
{
    printf("Enter number of student: "); 
    int n;
    scanf("%d", &n);
    getchar(); //Clearing input buffer.

    FILE *inputFilePointer = fopen("input.txt", "w");

    for (int i = 0; i < n; i++)  // Input taking and writing to file loop. 
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
        while((c=getchar())!='\n' && c!=EOF)
            ;  //Cleaning infput buffer. 
    }
    fclose(inputFilePointer);

    FILE *sourceFilePointer = fopen("input.txt", "r");
    FILE *outputFilePointer = fopen("output.txt", "w"); 

    for (int i = 0; i < n; i++)
    {
        char name[100]; 
        fgets(name, sizeof(name), sourceFilePointer);
        fprintf(outputFilePointer, name);

        int ID;
        fscanf(sourceFilePointer, "%d\n", &ID);
        fprintf(outputFilePointer,"%d\n" ,ID); 

        float CG;
        fscanf(sourceFilePointer, "%f\n", &CG);
        fprintf(outputFilePointer, "%f\n", CG);

        int a, b, d;
        fscanf(sourceFilePointer, "%d\n", &a); 
        fscanf(sourceFilePointer, "%d\n", &b);     
        fscanf(sourceFilePointer, "%d\n", &d);
        fprintf(outputFilePointer, "Total marks = %d\n", a + b + d); 
    }

    fclose(sourceFilePointer);
    fclose(outputFilePointer);
    return 0; 
}