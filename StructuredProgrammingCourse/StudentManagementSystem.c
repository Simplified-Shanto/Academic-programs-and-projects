#include<stdio.h> 
#include<stdlib.h> 


int main()
{
    int n;
    FILE *fptr;
    for (int i = 0; i < n; i++)
    {
        char name[50];
        int ID;
        float CG;
        int mark_phy, mark_chem, mark_math;
        fptr = fopen("studentinfo.txt", "a"); 
        printf("Name: ");
        fgets(name, sizeof(name),  stdin);
        //printf("Name = %s\n", name); 
        printf("ID: ");
        scanf("%d", &ID);
        printf("CG: "); 
        scanf("%f", &CG);
        printf("Phy_mark Chem_mark Math_mark: ");
        scanf("%d %d %d", &mark_phy, &mark_chem, &mark_math); 

        fprintf(fptr, name);
        fprintf(fptr, "\n"); 
        fprintf(fptr, ID);
        fprintf(fptr, "\n"); 
    }

    fclose(fptr); 
    return 0; 
}