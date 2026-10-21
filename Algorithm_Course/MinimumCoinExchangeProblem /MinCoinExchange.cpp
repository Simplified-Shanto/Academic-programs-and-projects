#include <algorithm>
#include <iostream>
#include <vector>

using namespace std; 


int main(){
    vector<int> coinValues = {1, 3, 4};
    int targetAmount = 6;
    int coinTypeCount = coinValues.size(); 

    vector<vector<int>> minCoin(coinTypeCount + 1, vector<int>(targetAmount + 1, 0));

    // More than targetAmount coins can never be part of a best answer here,
    // so targetAmount + 1 represents an amount that cannot be formed.
    int impossible = targetAmount + 1;

    // With no coin types available, only amount 0 can be made.
    for (int currentAmount = 1; currentAmount <= targetAmount; currentAmount++) {
        minCoin[0][currentAmount] = impossible;
    }


    // current coin type starts from 1 because, in our dp table, row 1 indicates the first coin type 
    
    for(int currentCoinType = 1; currentCoinType <= coinTypeCount; currentCoinType++)
    {
        int coinValue = coinValues[currentCoinType - 1];  // Since coinValues is using 0 based indexing 
        // now for this coinValue we'll check all the possible amount that we might need to make 
        for(int currentAmount = 0; currentAmount <= targetAmount; currentAmount++)
        {
            if(coinValue > currentAmount) { // we cannot use the coin. 
                minCoin[currentCoinType][currentAmount] = minCoin[currentCoinType-1][currentAmount]; 
            }
            else 
            {
                // Skipping uses only the earlier coin types (the previous row).
                int coinCountIfSkipped = minCoin[currentCoinType - 1][currentAmount];

                // Using stays in this row, so this coin type can be used again.
                int coinCountIfUsed = 1 + minCoin[currentCoinType][currentAmount - coinValue];

                minCoin[currentCoinType][currentAmount] = min(coinCountIfSkipped, coinCountIfUsed); 
            }
        }
    }

    return 0; 
}
