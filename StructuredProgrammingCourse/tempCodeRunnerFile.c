#include<stdio.h> 

// Write merge function that takes two sorted subarrays and merges them
// into a single sorted array

void merge(int original[100], int l, int m, int r)
{
    int temp[r-l+1], fp = l, sp = m + 1;
    for (int i = 0; i<r - l+1; i++)
    {
        if(fp <= m && sp <= r)
        {
            if(original[fp] <= original[sp])
            {
                temp[i] = original[fp++]; 
            }
            else if(original[sp] <= original[fp])
            {
                temp[i] = original[sp++]; 
            }
        }
        else
        {
            if(fp<=m) {
                temp[i] = original[fp++];
             }
             else if(sp<=r)
             {
                 temp[i] = original[sp++]; 
             }
        }
    }

    for (int i = 0, j = l; j <= r; i++, j++)
        original[j] = temp[i]; 
        
}

void mergeSort(int org[100], int l, int r)
{
    if(l < r)
    {
        int mid = (l + r)/2;
        mergeSort(org, l, mid);
        mergeSort(org, mid + 1, r);
        merge(org, l, mid, r); 
    }
    else 
    {
        return; 
    }

}


int main()
{
    int manga[5] = {1, 2, 3, 4, 5, -20, -15, -10, -5, 0};
    mergeSort(manga, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", manga[i]); 
    }

    return 0; 
}