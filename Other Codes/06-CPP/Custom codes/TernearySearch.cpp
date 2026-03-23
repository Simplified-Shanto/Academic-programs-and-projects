#include<iostream> 
#include<bits/stdc++.h>
using namespace std; // In C++, a namespace is a declarative region used to organize and group related code elements (such as variables, functions, and classes) into a specific scope. Its primary purpose is to prevent naming conflicts that can occur when multiple libraries or different parts of a large project use the same identifiers.

// Working of Ternary Search
// Given an array that first strictly decreases and then strictly increases, we want to find the index of the minimum element. This kind of array is known as a U-shaped or unimodal array.

// Input:  arr [] = [9, 7, 5, 2, 3, 6, 10]


int findMinIndex(vector<int>& arr)
{
    int low = 0, high = arr.size() - 1;
    int minIndex = -1; 

    while(low <= high)
    {
        //divide the range into three parts
        int mid1 = low + (high - low) / 3; 
        int mid2 = high - (high - low) / 3; 

        // if both mid1 and mid2 point to equal values -> narrow the search 
        if(arr[mid1] == arr[mid2])
        {
            // Move towards the center
            low = mid1 + 1;
            high = mid2 - 1; 

            // tentatively(subject to further confirmation; not definitely.) store mid1 as the potential max
            // If the pattern keeps going till the end of this loop, then mid1 and mid2 will overlap, finding the index of the minimum element .
            minIndex = mid1; 
        }

        // if arr[mid1] < arr[mid2], the minimum lies in the left part
        // (including mid1)
        else if(arr[mid1] < arr[mid2])
        {
            high = mid2 - 1; 
            //update with better candidate
            minIndex = mid1; 
        }
        // if arr[mid1] > arr[mid2], the minimum lies in the right part 
        // including mid2 
        else {
            low = mid1 + 1; 
            // update with better candidate
            minIndex = mid2; 

        }
    }

    return minIndex; 
}

int main()
{

    vector<int> arr = {9, 7, 6, 8,0, 1, 2, 3, 6, 10}; 

    int idx = findMinIndex(arr);
    cout << idx << endl;
}