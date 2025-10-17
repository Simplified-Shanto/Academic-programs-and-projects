#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r = 3, c = 2;

    // Allocate contiguous block
    int *arr = malloc(r * c * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input
    printf("Enter %d elements:\n", r * c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", (arr + i * c + j));
        }
    }

    // Output
    printf("Matrix elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", *(arr + i * c + j));
        }
        printf("\n");
    }

    free(arr);
    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int r = 3, c = 2;
//     int *arr = malloc(r*c*sizeof(int)); // arr is the pointer to the first memory address in this contiguous set of memory addresses.

//     for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             scanf("%d", (arr + i*r + j));
//         }
//     }

//         for (int i = 0; i < r; i++)
//     {
//         for (int j = 0; j < c; j++)
//         {
//             printf("%d ", *(arr + i*r + c));
//         }
//         printf("\n");
//     }
// }

// // Implement 2D array with pointer to array approach
// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int row = 3, column = 4;
//     int (*x)[column];
//     x = malloc(row * sizeof(*x));

//     for (int i = 0; i< row; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             scanf("%d", *(x + i) + j);
//         }
//     }

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < column; j++)
//         {
//             printf("%d ", *(*(x + i) + j));
//         }
//         printf("\n");
//     }
//         return 0;
// }

// // Implement, populate and print a 2D array with double pointer approach
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int rows = 3, cols = 4;
//     int **arr;

//     // Allocate memory for row pointers
//     arr = malloc(rows * sizeof(*arr));

//     // Allocate each row
//     for (int i = 0; i < rows; i++) {
//         arr[i] = malloc(cols * sizeof(*arr[i]));
//     }

//     // Populate the array
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             arr[i][j] = (i + 1) * (j + 1); // just an example pattern
//         }
//     }

//     // Print the array
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%3d ", arr[i][j]);
//         }
//         printf("\n");
//     }

//     // Free memory
//     for (int i = 0; i < rows; i++) {
//         free(arr[i]);
//     }
//     free(arr);

//     return 0;
// }

// Implement, populate and print a  2D array with pointerToArray method

// #include<stdio.h>
// #include<stdlib.h>

// int main()
// {
//     int columns = 2, rows = 3;
//     int (*pointerToArray)[columns]; //pointerToArray points to an 1D array having four elements. == the first row with 4 columns

//     pointerToArray = malloc(rows * sizeof(*pointerToArray)); // *pointerToArray is the array itself, sizeof((*pointerToArray)) = total memory required for storing "columns" number of integer
//     // A continuous segment of memory is allocated for the (rows x columns) elements of the 2D array.
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j<columns; j++)
//         {
//             scanf("%d", *(pointerToArray + i) + j);
//         }
//     }

//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < columns; j++)
//         {
//             printf("%d ", *(*(pointerToArray + i) + j));
//         }
//         printf("\n");
//     }
// }

// // Create a multidimensional array with pointers, populate it, print it

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// //  x → pointer to the first row
// // *x → the row (decays to pointer to first element of row) (dereferencing for the first time)
// // **x → the first integer in the first row (dereferencing for the second time)
//     int row = 3, column = 1;
//     int (*x)[column]; // Pointer to an 2 element array.
//     printf("Size of s = %zu", sizeof(*x));

//     x = malloc(row * sizeof(*x));
//     //printf("Size of s = %zu", sizeof(*x));

//     for (int i = row - 1; i >= 0; i--)
//     {
//         for (int j = column - 1; j >= 0; j--)
//         {
//             scanf("%d", *(x + i) + j);
//         }
//     }

//     // x  = pointer to the first row,
//     // *x  = the first row itself (which is an 1D array, and such an array defined by pointers always point to the first element of the array)  = pointer to the first element of the row
//     // (x + 1) = pointer to the second row
//     // *(x + 1) = the second row itself = pointer to the first element (column) of the second row
//     // (x + 2) = pointer to the third row
//     // *(x + 2) = the third row itself  = pointer to the first element (column) of the third row.

//     for (int i = row - 1; i >= 0; i--)
//     {
//         for (int j = column - 1; j >= 0; j--)
//         {
//             printf("%d ", *(*(x + i) + j));
//         }
//     }
//     return 0;
// }