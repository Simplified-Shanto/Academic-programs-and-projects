#include<stdio.h> 


int main()
{
    int arr[8] = {1, 3, 2, 90, 21, 38, 252, 12}; 

    for(int i = 1; i< 8; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if(arr[j] > arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp; 
            }
            else
                break; 
        }
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]); 
    }
}