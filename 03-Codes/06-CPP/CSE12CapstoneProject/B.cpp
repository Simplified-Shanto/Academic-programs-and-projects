#include<bits/stdc++.h> 

using namespace std; 


int main()
{
  int n, m;
    cin >> n >> m;
    vector<int> a(n);
  //  for(auto &x: a) scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; 
    }

    sort(a.begin(), a.end()); 

    vector<pair<int, int>> b;
    for (int i = 0; i < m; i++)
    {
        int bi;
        cin >> bi;
        b.push_back({i, bi}); 
    }

    stable_sort(b.begin(), b.end(), [](const pair<int, int> &a, const pair<int, int> &c)
                { return a.second < c.second;  });

    int pos = 0; 
    for (int i = 0; i < m; i++)
    {

        while(a[pos] <= b[i].second && pos!=n)
        {
            pos++; 
        }

        b[i].second = pos; 
    }


    stable_sort(b.begin(), b.end(), [](const pair<int, int> &a, const pair<int, int> &c)
    {   return a.first < c.first;             });

    for (int i = 0; i < m; i++)
    {
        cout << b[i].second << " "; 
    }

    return 0;
}

