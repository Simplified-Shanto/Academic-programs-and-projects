

    #include <bits/stdc++.h>
    using namespace std;

    #ifndef ONLINE_JUDGE
    #define db(x)          \
        cout << #x << " "; \
        show(x);           \
        cout << "\n";
    #else
    #define db(x)
    #endif
    #define vi vector<int>
    #define vs vector<string>
    #define vlli vector<long long int>
    #define vivi vector<vector<int>>
    #define pb push_back
    #define pob pop_back
    #define pii pair<int, int>
    #define pis pair<int, string>
    #define pci pair<char, int>
    #define pll pair<long long int, long long int>
    #define mp make_pair
    #define sd second
    #define ft first
    #define lli long long int
    #define ulli unsigned long long int
    #define for0(i, n) for (int i = 0; i < n; i++)
    #define for1(i, n) for (int i = 1; i <= n; i++)
    #define Asort(v) sort(v.begin(), v.end());
    #define Dsort(v) sort(v.rbegin(), v.rend());
    #define Ssort(v) stable_sort(v.begin(), v.end());
    #define Rev(v) reverse(v.begin(), v.end());
    lli mod = 1e9 + 7;
    lli mod1 = 998244353;

    void show(int a) { cout << a; }
    void show(lli a) { cout << a; }
    void show(char a) { cout << a; }
    void show(ulli a) { cout << a; }
    void show(string s) { cout << s; }
    void show(bool a) { cout << a; }

    template <class T, class M>
    void show(pair<T, M> p)
    {
        cout << "(" << p.ft << "," << p.sd << ")";
    }
    template <class T>
    void show(vector<T> v)
    {
        cout << "[ ";
        for (T i : v)
        {
            show(i);
            cout << " ";
        }
        cout << "]\n";
    }
    template <class T>
    void show(set<T> s)
    {
        cout << "[ ";
        for (T i : s)
        {
            show(i);
            cout << " ";
        }
        cout << "]";
    }
    template <class T>
    void show(multiset<T> s)
    {
        cout << "[ ";
        for (T i : s)
        {
            show(i);
            cout << " ";
        }
        cout << "]";
    }
    template <class T>
    void show(priority_queue<T> p)
    {
        cout << "[ ";
        while (p.empty() == 0)
        {
            cout << p.top();
            p.pop();
            cout << " ";
        }
        cout << "]";
    }
    template <class T>
    void show(priority_queue<T, vector<T>, greater<T>> p)
    {
        cout << "[ ";
        while (p.empty() == 0)
        {
            cout << p.top();
            p.pop();
            cout << " ";
        }
        cout << "]";
    }
    template <class T, class M>
    void show(unordered_map<T, M> m)
    {
        cout << "[ ";
        for (auto x : m)
        {
            show(x);
            cout << " ";
        }
        cout << "]";
    }
    template <class T, class M>
    void show(map<T, M> m)
    {
        cout << "[ ";
        for (auto x : m)
        {
            show(x);
            cout << " ";
        }
        cout << "]";
    }



    bool testcase = 0;
    void solve()
    {
    //     int n, m;
    //     cin >> n >> m;

    //     vector<pair<int, int>> ship;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int bi;
    //         cin >> bi;
    //         ship.push_back({i, bi}); 
    //     }

    //     vector<pair<int, int>> base(m); 
    
    //     for (int i = 0; i < m; i++)
    //     {
    //         cin >> base[i].first >> base[i].second;  // defensive power - gold 
    //     }

    //     stable_sort(ship.begin(), ship.end(), [](const pair<int, int> &a, const pair<int, int> &c)
    //                 { return a.second < c.second;  }); // Sorting according to the attacking power of ship 
    //     stable_sort(base.begin(), base.end(), [](const pair<int, int> &a, const pair<int, int> &c) 
    //                 { return a.first < c.first;  }); //Sorting according to the order of the defensive power. 
    
    //    // show(base); 
    //     int pos = 0; 
    //     int goldSum = 0; 
    //     for (int i = 0; i < n; i++)
    //     {
    //                 //defPower    //attackingPower
    //         while(base[pos].first <= ship[i].second && pos!=m)
    //         {
    //             goldSum+=base[pos].second; 
    //             pos++; 
    //         }
    //         ship[i].second = goldSum; 
    //     }

    //     stable_sort(ship.begin(), ship.end(), [](const pair<int, int> &a, const pair<int, int> &c)
    //     {   return a.first < c.first;             });

    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << ship[i].second << " "; 
    //     }
    int s, b; 
    cin >>s >> b; 
    vi ships(s); 
    for(auto &x: ships) { cin >> x; }
    vector<pair<int,int>> base(b);
for (int i = 0; i < b; i++) cin >> base[i].first >> base[i].second;

sort(base.begin(), base.end());

vector<int> defense(b);
vector<long long> prefix(b);

for (int i = 0; i < b; i++) {
    defense[i] = base[i].first;
    prefix[i] = base[i].second + (i ? prefix[i - 1] : 0);
}

for (int x : ships) {
    int k = upper_bound(defense.begin(), defense.end(), x) - defense.begin();
    cout << (k == 0 ? 0 : prefix[k - 1]) << ' ';
}



    }
        











    

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t = 1;
        if (testcase == true)
        {
            cin >> t;
        }
        while (t--)
        {
            solve();
        }
    }