// Implement multiplication of 2 matrices. Here matrices are 2D arrays created with the help of pointers. 

#include<stdio.h> 
#include<stdlib.h> 

int main()
{
    int r1, c1, r2, c2;
    printf("Enter dimension of the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Press \'ENTER\' after typing each row.\n");

    int (*mat1)[r1];
    //mat1 = malloc(c1 * sizeof(mat1));

    for (int i = 0; i < r1; i++)
    {
        *mat1[i] = malloc(c1 * sizeof(int)); 
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", (mat1[i] + j));
        }
    }

        for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", *(mat1[i] + j));
        }
        printf("\n"); 
    }

    // printf("Enter the dimension of the second matrix: "); 
    // scanf("%d %d", &r2, &c2); 

    // while(c1!=r2)
    // {
    //     printf("Invalid dimension!\n For myltiplying two matrices, column number of first matrix must be equal to the row number of the second matrix!\n"); 
    //     printf("Enter the dimension of the second matrix: "); 
    //     scanf("%d %d", &r2, &c2); 
    // }

    // printf("Press \'ENTER\' after typing each row.\n");

    // int (*mat2)[r2];
    // mat2 = malloc(c2 * sizeof(mat2)); 

    // for (int i = 0; i < r2; i++)
    // {
    //     for (int j = 0; j < c2; j++)
    //     {
    //         scanf("%d", (mat2[i] + j)); 
    //     }
    // }

    //     for (int i = 0; i < r2; i++)
    // {
    //     for (int j = 0; j < c2; j++)
    //     {
    //         printf("%d ", *(mat2[i] + j)); 
    //     }
    //     printf("\n"); 
    // }







    // for (int i = 0; i < r1; i++)
    // {
    //     free(mat1[i]); 
    // }

    // for (int i = 0; i < r2; i++)
    // {
    //     free(mat2[i]); 
    // }
        return 0; 
}








// Note that, key challenge in this problem is to form the multiplication loop. 

// #include<stdio.h> 

// int main()
// {
//     int r1, c1, r2, c2;
//     printf("Enter dimension of the first matrix: ");
//     scanf("%d %d", &r1, &c1);
//     printf("Press \'ENTER\' after typing each row.\n");
//     int mat1[r1][c1]; 
//     for (int i = 0; i < r1; i++)
//     {
//         for (int j = 0; j < c1; j++)
//         {
//             scanf("%d", &mat1[i][j]); 
//         }
//     }


//     printf("Enter the dimension of the second matrix: "); 
//     scanf("%d %d", &r2, &c2); 

//     while(c1!=r2)
//     {
//         printf("Invalid dimension!\n For myltiplying two matrices, column number of first matrix must be equal to the row number of the second matrix!\n"); 
//         printf("Enter the dimension of the second matrix: "); 
//         scanf("%d %d", &r2, &c2); 
//     }

//     printf("Press \'ENTER\' after typing each row.\n");

//     int mat2[r2][c2]; 

//     for (int i = 0; i < r2; i++)
//     {
//         for (int j = 0; j < c2; j++)
//         {
//             scanf("%d", &mat2[i][j]); 
//         }
//     }

//     //     for (int i = 0; i < r2; i++)
//     // {
//     //     for (int j = 0; j < c2; j++)
//     //     {
//     //         printf("%d ", mat2[i][j]); 
//     //     }
//     //     printf("\n"); 
//     // }

//     // int r1 = 2, r2 = 2, c1 = 2, c2 = 2;
//     // int mat1[2][2] = {{1, 2}, {3, 4}}; 
//     // int mat2[2][2] = {{1, 2}, {3, 4}}; 

//     int productMat[r1][c2];

//     printf("Here's the product matrix: \n"); 
    
//     // note that r1 = c2, now we need to traverse the mat1rowIndex row of mat1 and mat2columnIndex column of mat2 simultaneously and multiply the respective elements and add it to a sum.
//     for (int mat2columnIndex = 0; mat2columnIndex < c2; mat2columnIndex++)
//     {
//         for (int mat1rowIndex = 0; mat1rowIndex < r1; mat1rowIndex++)
//         {
//                     int productSum = 0;
//                     for (int i = 0; i < r2; i++)
//                     {
//                         productSum += (mat1[mat1rowIndex][i] * mat2[i][mat2columnIndex]);
//                     }
//                     productMat[mat1rowIndex][mat2columnIndex] = productSum; 
//         }
//     }

//     for (int i = 0; i < r1; i++)
//     {
//         for (int j = 0; j < c2; j++)
//         {
//             printf("%d ", productMat[i][j]); 
//         }
//         printf("\n"); 
//     }

//         return 0; 
// }