#include<iostream> 
#include<vector> 
using namespace std; 




//This is a simple version where the pivot is always the last element. 

void quickSortLastPivot(vector<int> &v){
    vector<int> leftPartition; 
    vector<int> rightPartition;
    
    int pivotIndex = v.size() -1; 

    for(int i = pivotIndex - 1; i>=0; i--)
    {
        if(v[i] <= v[pivotIndex] )
        {
            leftPartition.push_back(v[i]); 
        }
        else {
            rightPartition.push_back(v[i]); 
        }
    }

    int newPivotIndex = leftPartition.size();

    if(leftPartition.size() > 1)
    quickSort(leftPartition); 

    if(rightPartition.size() > 1)
    quickSort(rightPartition); 

//After we've sorted the left and right partition separately, we are merging it back to the original array 
    for(int i = 0; i< v.size(); i++) 
    {
        if(i<leftPartition.size()) {
            v[i] = leftPartition[i]; 
        }
        else if( i  > leftPartition.size() ){
            v[i] = rightPartition[i - leftPartition.size() -1]; 
        }
        else if(i == leftPartition.size())
        {
            v[leftPartition.size()] = v[pivotIndex]; 
        }
    }
    
}

//This is a simple version works with any pivot

void quickSort(vector<int> &v, int pivotIndex){
    vector<int> leftPartition; 
    vector<int> rightPartition;
    
    int pivotIndex = v.size() -1; 

    for(int i = pivotIndex - 1; i>=0; i--)
    {
        if(v[i] <= v[pivotIndex] )
        {
            leftPartition.push_back(v[i]); 
        }
        else {
            rightPartition.push_back(v[i]); 
        }
    }

    int newPivotIndex = leftPartition.size();

    if(leftPartition.size() > 1)
    quickSort(leftPartition); 

    if(rightPartition.size() > 1)
    quickSort(rightPartition); 

//After we've sorted the left and right partition separately, we are merging it back to the original array 
    for(int i = 0; i< v.size(); i++) 
    {
        if(i<leftPartition.size()) {
            v[i] = leftPartition[i]; 
        }
        else if( i  > leftPartition.size() ){
            v[i] = rightPartition[i - leftPartition.size() -1]; 
        }
        else if(i == leftPartition.size())
        {
            v[leftPartition.size()] = v[pivotIndex]; 
        }
    }
    
}




int main()
{
    vector<int> V = {12, 7, 9, 8, 14, 11}; 
    quickSort(V); 

    for(auto x: V)
    {
        cout << x << " " << endl ; 
    }

}