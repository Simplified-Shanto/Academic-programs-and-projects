#include<iostream> 
#include<vector> 
#include<algorithm> 
#include<iomanip> 


using namespace std; 

struct Item { 
    int id; 
    double profit; 
    double weight; 
};

bool compare(Item A, Item B)
{
    return (A.profit / A.weight) > (B.profit / B.weight); 
}

int main(){
    int n; 
    cout << "Enter number of items: "; 
    cin >> n; 
     
    vector<Item> items(n); 

    double capacity; 
    cout << "Enter knapsack capacity: "; 
    cin >> capacity; 
    
    cout << "Enter Profit and Weight for each item: \n"; 

    for(int i = 0; i<n; i++)
    {
        items[i].id = i + 1; 
        cin >> items[i].profit >> items[i].weight; 

    }


    // Sort according to profit/weight ratio 
    sort(items.begin(), items.end(), compare); 


    double totalProfit = 0.0; 

    cout << "\nSelected Items: \n"; 

    for(int i = 0; i<n; i++) {
        if (capacity == 0)
        break; 

        if(items[i].weight <= capacity) {
            //Take the whole item 
            cout << "Item " << items[i].id << " -> 100%\n"; 
            totalProfit+=items[i].profit; 
            capacity-=items[i].weight; 
        }
        else // Take the fraction of the item 
        {
            double fraction = capacity/items[i].weight; 
            totalProfit+= fraction * items[i].profit; 
            cout << "Item " << items[i].id << fraction*100 << " %"; 
            capacity=0; 
        }
    }

    cout << fixed << setprecision(2); 
    cout << "\nMaximum Profit = " << totalProfit << endl; 

    return 0; 
} 