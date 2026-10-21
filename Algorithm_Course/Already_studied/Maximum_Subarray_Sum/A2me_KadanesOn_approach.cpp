#include<iostream> 
#include<vector> 
#include<climits> 
using namespace std; 


//kadane's algorithm. 


int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; 
    int best_sum = arr[0]; 
    int current_sum = arr[0]; 

    for(int i = 1; i< arr.size(); i++)
    {
        if(current_sum < 0) { // Start a new subarray 
            current_sum = arr[i]; 
        }
        else { // else, continue extending the previous subarray 
            current_sum+=arr[i]; 
        }
        best_sum = max(best_sum, current_sum); 
    //    cout << "Current sum = " << current_sum << endl; 
    }

    cout << "Maximum subarray sum: " << best_sum << endl; 
}