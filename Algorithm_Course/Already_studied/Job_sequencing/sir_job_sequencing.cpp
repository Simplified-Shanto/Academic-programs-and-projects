#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator function
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter Job ID, Deadline, Profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Sort jobs by profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Slot array
    vector<char> slot(maxDeadline + 1, '-');
    vector<bool> occupied(maxDeadline + 1, false);

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (!occupied[j]) {
                occupied[j] = true;
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "\nSelected Jobs:\n";
    for (int i = 1; i <= maxDeadline; i++) {
        if (occupied[i])
            cout << "Time Slot " << i << " -> Job " << slot[i] << endl;
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
