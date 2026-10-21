#include <iostream>
#include <vector>

using namespace std;


// In the Profit table, a particular cell Profit[i][w] means: Maximum profit using the first i items, with capacity at most w. 
// So, Profit[2][4] means: Using items 0 and 1 only, what is the maximum profit that fits in capacity 4? 


int main() {
    // Item i has weight[i] and profit[i].
    vector<int> weight = {1, 3, 4, 5};
    vector<int> profit = {1, 4, 5, 7};
    int capacity = 7;
    int itemCount = weight.size();

    // Profit[i][w] will store the best profit obtainable by considering the
    // first i items while using a knapsack with capacity w.
    // Row 0 and column 0 stay 0: no items or no capacity gives no profit.
    vector<vector<int>> Profit(itemCount + 1, vector<int>(capacity + 1, 0)); // a (itemCount+1)*(capacity+1) table with all cell = 0 

    // Next: fill Profit row by row.
    // For every item, decide whether skipping it or taking it gives more profit.
    for(int i = 1; i<= itemCount; i++){ // Enumering the rows of the Profit table 
        int currentItemWeight = weight[i-1]; // The Profit table has an extra row 0 for "no items", while the weight and profit vectors start at index 0. 
        int currentItemProfit = profit[i-1]; 

        for(int w = 0; w <=capacity; w++){ // Enumerating the columns of the Profit table. 
            if (currentItemWeight > w) {
                // The item cannot fit, so copy the best answer from the previous row for this item, since the column rep
                Profit[i][w] = Profit[i-1][w]; 
            }
            else { // the item fits. 
                int skippedProfit = Profit[i-1][w]; ;// the profit we'll attain if we skip this item
                int takenProfit = currentItemProfit + Profit[i-1][w-currentItemWeight]; // Profit of the item + Best profit for the remaining capacity after taking this item 
                Profit[i][w] = max(skippedProfit, takenProfit); 
            }
        }
    }
    // Next: print Profit[itemCount][capacity].

    cout << "Maximum profit: " << Profit[itemCount][capacity] << endl; 

    return 0;
}
