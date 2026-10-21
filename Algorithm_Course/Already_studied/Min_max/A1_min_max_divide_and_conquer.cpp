#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// This structure will hold both answers returned by one recursive call.
struct MinMax {
    int minimum;
    int maximum;
};

// Next: implement divide-and-conquer for the inclusive range [left, right].
MinMax findMinMax(const vector<int>& arr, int left, int right) {
    // Your base cases and recursive split go here.
    if(left==right)
    {
        MinMax m = {arr[left], arr[left]}; 
        return m; 
    }
    else if(left+1==right){
        MinMax m; 
        if(arr[left]>arr[right]){  
             m.minimum = arr[right]; 
             m.maximum = arr[left]; 
            } 
        else {
            m.minimum = arr[left]; 
            m.maximum = arr[right]; 
        }
        return m; 
    }
    else 
    {
        int mid = (left+right)/2; 

        MinMax LMinMax = findMinMax(arr, left, mid);
        MinMax RMinMax = findMinMax(arr, mid+1, right); 
        
        MinMax m = {min(LMinMax.minimum, RMinMax.minimum), max(LMinMax.maximum, RMinMax.maximum)}; 
        return m; 
    }
}

int main() {
    vector<int> arr = {7, 2, 9, 4, 1, 6};

    // Next: call findMinMax(arr, 0, arr.size() - 1) and print its result.

    MinMax m = findMinMax(arr, 0, arr.size()-1); 
    cout << "Min = " << m.minimum << " Max = " << m.maximum << endl; 
    return 0;
}
