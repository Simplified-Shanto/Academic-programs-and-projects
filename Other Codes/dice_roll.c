// #include<stdio.h> 
// #include<stdlib.h> 

// int main()
// {
//     int t; scanf("%d", &t); 
//     while(t--)
//     {
        
//         int n, count = 0;
//         scanf("%d", &n); 
//         int *arr = malloc(n*sizeof(int));
//         //printf("Ok\n"); 
//         for (int i = 0; i < n; i++)
//         {
//             scanf("%d", &arr[i]);
//         }

//         for (int i = 1; i < n; i+=2)
//         {
//             if(arr[i] == 7 - arr[i-1] || arr[i] == arr[i-1])
//             {
//                 count++; 
//             }
//         }

//          printf("%d\n", count); 
//     }
//     return 0; 
// }


#include<stdio.h> 

int main()
{
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            for (int k = 1; k <= 6; k++)
            {
                printf("%d %d %d\n", i, j, k); 
            }
        }
    }
        return 0; 
}