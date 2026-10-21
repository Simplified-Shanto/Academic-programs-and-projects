#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int id;
    double profit;
    double weight;
};

// Comparator function
bool compare(Item a, Item b) {
    return (a.profit / a.weight) > (b.profit / b.weight);
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter Profit and Weight for each item:\n";
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        cin >> items[i].profit >> items[i].weight;
    }

    double capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort according to profit/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;

    cout << "\nSelected Items:\n";

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            // Take the whole item
            cout << "Item " << items[i].id
                 << " -> 100%\n";

            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else {
            // Take fraction of the item
            double profit_weight_ratio = items[i].profit / items[i].weight;

            cout << "Item " << items[i].id
                 << " -> " << profit_weight_ratio * 100 << "%\n";

            totalProfit += capacity  * profit_weight_ratio;
            capacity = 0;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
