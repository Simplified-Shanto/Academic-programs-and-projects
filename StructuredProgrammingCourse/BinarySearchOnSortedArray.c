#include<stdio.h> 

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    int l = 0, r = 4, src = 60, mid = (l+r)/2;


    while(arr[mid]!=src)
    {
        if(l==r)
        {
            printf("Not found!\n");
            return 0; 
        }

        if(arr[mid] < src)
        {
            l = mid + 1;  // Since the element is not present in mid, we'll not consider the position mid in the next iteration, rather set the element before mid as the next left limit. 
        }
        else if(arr[mid] > src){
            r = mid - 1; 
        }

        mid = (l + r) / 2; 
    }

    printf("Element found at %d", mid); 

    return 0; 
}