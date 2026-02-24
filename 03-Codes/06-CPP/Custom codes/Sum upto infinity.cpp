#include<bits/stdc++.h>
using namespace std; 


int main()
{
    int ans = 0; 
    for(int i = 1; i<=160; i++)
    {
        cout << " x = " << i << " f(x) = " << 80*i - i*i << "\n"; 
        ans  = max(ans, 80*i - i*i ); 
    }

    cout << "Ans is " << ans << "\n"; 
}