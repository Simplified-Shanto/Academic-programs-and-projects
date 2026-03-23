#include<bits/stdc++.h>
using namespace std;

int HCF(int a,int b){
  if(a>b) swap(a,b);
 int remainder, divisor = a, quotient,dividend = b;
 remainder = dividend % divisor;
 while(remainder!=0){
        dividend = divisor;
    divisor = remainder;
    remainder =  dividend%divisor;
 }

 return divisor;
}

int main(){
int a,b; while(cin>>a>>b){
 cout << HCF(a,b) << endl;
}
return 0;
}
