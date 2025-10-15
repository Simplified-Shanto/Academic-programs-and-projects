#include<stdio.h> 

int main()
{
    int arr[8] = {1, 3, 2, 90, 21, 38, 252, 12};

    for (int i = 0; i < 8; i++)
    {
        int min = arr[i];
        int minIndex = i; 

        for (int j = i + 1; j < 8; j++)
        {
            if(min > arr[j]) {
                min = arr[j];
                minIndex = j; 
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp; 
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]); 
    }
}