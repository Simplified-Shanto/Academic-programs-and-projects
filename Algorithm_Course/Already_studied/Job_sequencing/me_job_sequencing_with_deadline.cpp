#include<algorithm> 
#include<tuple> 
#include <iostream> 

using namespace std; 

// {profit, deadline, id}
vector<tuple<int, int, int>> job = {
    {100, 2, 0},
    {19,  1, 1},
    {27,  2, 2},
    {25,  1, 3},
    {15,  3, 4}
};

int slot[10000] = {0}; //declares a fixed-size array of 10,000 integers and initializes every element to 0.
int totalProfit = 0; 

vector<tuple<int, int, int, int>> scheduled_jobs; // Assigned Slot, Job Id, Profit, deadline 

int main ()
{
    sort(job.begin(), job.end()); 
    cout << " Sorted jobs are: " << endl; 


    for(int i = job.size() - 1; i>=0; i--)
    {
        int deadline = get<1>(job[i]); 
        int profit = get<0>(job[i]); 
        int jobId = get<2>(job[i]); 

        cout << " jobId: " << jobId << " profit: " << profit << " deadline: " << deadline << endl ; 

        int assignedSlot = -1; 

        for(int j = deadline; j>=1; j--)
        {
            if(slot[j]==0){
                assignedSlot = j; break; 
            }
        }

        if(assignedSlot!=-1){
            slot[assignedSlot] = 1; 
            scheduled_jobs.push_back({assignedSlot, jobId, profit, deadline}); 
            totalProfit+= profit; 
        }
        else {
            cout << "Job " << jobId << " with profit " << profit << " cannot be scheduled" << endl; 
        }
    }

    sort(scheduled_jobs.begin(), scheduled_jobs.end()); // we are having the jobs sorted according to the assigned slot 

    cout << "Total profit = " << totalProfit <<  " from the following scheduled jobs: "<< endl; 
    for(auto x: scheduled_jobs)
    {
        cout << "Slot: " << get<0>(x) << " Job " << get<1>(x) << " (profit: " << get<2>(x) << ", deadline " << get<3>(x) << " )" << endl; 
    }
}