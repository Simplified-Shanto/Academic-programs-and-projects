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
    int manga[10] = {1, 2, 3, 4, 5, -20, -15, -10, -5};
    mergeSort(manga, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", manga[i]); 
    }

    return 0; 
}








// #include<stdio.h> 

// void merge(int num[100],int l,int m,int r)
// {
//     int fp = l, sp = m + 1;
//     int temp[r-l+1];

//      int i = 0;
//      for (     ; i <r-l+1; i++)
//      {
//         if(fp <= m && sp <= r)
//         {
//             if(num[fp] < num[sp]) {  temp[i] = num[fp++]; }
//             else { temp[i] = num[sp++]; }
//         }
//         else if(fp<=m){ temp[i] = num[fp++]; }
//         else if(sp<=r)  temp[i] = num[sp++];
//     }
//      for (int i = l, j = 0; i <= r; i++, j++) {
//          num[i] = temp[j];
//          //printf("%d ", temp[i - l]);
//      }
// }


// //Implement merge sort
// void mergeSort(int num[100], int l , int r)
// {
//     if(l < r )
//     {
//         int mid = (l + r) / 2;
//         mergeSort(num, l, mid);
//         mergeSort(num, mid + 1, r);
//         merge(num, l, mid, r);
//     }
//     else
//     {
//         return;
//     }
// }

// int main()
// {
//     int n = 5;
//     int num[5] = { 23, 11, 15, 10, 9};
//     //merge(num, 0,(n-1)/2, n-1);

//     mergeSort(num, 0, n - 1);

//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", num[i]);
//     }
//     return 0;
// }
