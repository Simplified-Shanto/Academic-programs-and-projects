#include<bits/stdc++.h>
using namespace std;

//This code takes an integer as input
//Then prints the prime numbers smaller or equal to the inputted integer
//The famous algorithm "The sieve of Eratosthenes" has been used here

int main(){

 int n,a,b,c,d,e;
 while(cin>>n){
 vector<bool> v(n+1,true);

for(int i = 2;i*i<=n;i++)
    if(v[i])
        for(int j = i*i; j<=n;j+=i)
            v[j] = false;

for(int i = 2;i<=n;i++)
    if(v[i]) cout << i << " ";
cout << endl;
}
return 0;
}
