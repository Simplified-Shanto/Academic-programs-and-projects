#include<bits/stdc++.h>
using namespace std; 

int main()
{
    vector<string> v; 
    string s; 
    while(cin >> s)
    {
        v.push_back(s); 
    }

    cout <<"We've found " <<v.size()  << " strings" << "\n";
    // for(auto x: v)
    // {
    //     int flag = 0; 
    //     flag = (x=="Ans:"); 
    //    if(flag ) { cout << "\n\n"; }
    //     cout << x << " "; 

    // } 
    int sz  = v.size(); 
    string q = "Ques"; 
    string ans = "Ans:"; 
    for(int i = 0; i<v.size(); i++) 
    {
        int f1 = 0, f2 = 0; 
        if((i==0 || i+1 < sz) && v[i].size()>=4)
        {
            f1 = 1; f2 = 1; 
            for(int j = 0; j<4; j++)
            {
                
                f1&=(q[j]==v[i][j]); 
                f2&=(ans[j]==v[i][j]); 
            }
        }
        if(f2) { cout << "\n\n"; }
        if(f1) { cout << "\n\n\n" ; }
        //if(f1||f2) { cout << "\n";}; 
        cout << v[i] << " "; 
    }
}