#include<iostream> 
#include<vector> 
#include<climits> 
using namespace std; 

// Naive approach having N x N x N runtime 
long long maximumSubarraySumN3(const vector<int>& arr) {
    int n = arr.size(); 
    long long maximumSum = LLONG_MIN; 

    for(int left = 0; left < n; left++)
    {
        for(int right = left; right < n; right++)
        {
            long long currentSum = 0; 
            for(int i = left; i < right; i++)
            {
                    currentSum+=arr[i]; 
            }

            maximumSum+=currentSum; 
        }
    }
    return maximumSum; 
}

// Improved approach having N x N complexity 
long long maximumSubarraySumN2(const vector<int>& arr) {
    int n = arr.size(); 
    long long maximumSum = LLONG_MIN; 

    for(int left = 0; left < n; left++) {
        long long currentSum = 0 ;

        for(int right = left; right < n; right++) {
            currentSum += arr[right]; 
            maximumSum = max(maximumSum, currentSum); 
        }
    }

    return maximumSum; 
}


int main()
{
    vector<int> arr = {10, 3, -5, 6, 7, -2}; 
    cout << maximumSubarraySumN2(arr) << endl; 
}