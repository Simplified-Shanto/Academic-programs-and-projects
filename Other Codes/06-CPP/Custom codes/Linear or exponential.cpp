/*
8-31-2022 

This code is inspired by Khan-Academy-Algebra1-Exponential vs. Linear
growth or decay. The main purpose of implementing this one is to avoid 
the tedious task to analyze tables with differences and ratios. 

Most interestingly, it provides you the final answer you require. 
Only thing you need to do: 
1. Enter the time difference on the first line. 
2. Keep entering the data points on the table sequentially. 



*/

#include<bits/stdc++.h> 
using namespace std; 

int main()
{
     double td; //interval or time difference. 
      cin >> td; 
   double x; //data points
   double ld = 0, ed  = 0; //linear difference and exponential difference 
                           //respectively. 
   vector<double> v; 
   vector<double> difDev; //deviation from the average difference rate
   vector<double> ratioDev;  //deviation from the average ratio rates
   double sa = 0, sb = 0; 
   while(cin >> x)
   {
    v.push_back(x); 
   }
        cout << "Difference  Rate          Ratio    Rate\n"; 
        cout << "----------  ----          -----    ----\n"; 
   for(int i = 1; i<v.size(); i++)
   {
     double difference = v[i] - v[i-1]; 
     double ratio = v[i]/v[i-1]; 
        cout <<fixed << setprecision(2) <<  
         difference << "     " <<   difference/td << "          " << v[i]/v[i-1]  << "     " << pow(ratio, 1/td) << "\n"; 
         difDev.push_back(difference/td); 
         ratioDev.push_back(ratio/td); 
          sa+=difference/td; 
         sb+=pow(ratio, 1/td); 
   }
     double sz = difDev.size(); 
     sa/=sz; //Finding the average differences in difference rates. 
     sb/=sz; //Finding the average differences in ratio rates. 

     for(int i = 0; i<difDev.size(); i++)
     {
          ld+=abs(sa - difDev[i]); 
          ed+=abs(sb - ratioDev[i]); 
     }

cout << "Seems to be: \n";

     if(ld < ed)
     { 
          cout << "LINEAR with an equation: ";

          cout << "M(x) = " << v[0]<<(sa>0?" + ":" - ") <<  abs(sa) << ".x\n" ; 
     }
else
     {
      cout << "EXPONENTIAL with an equation: "; 
      cout << fixed << "M(x) = "  << v[0] << ".(" << sb <<")^x" << "\n"; 
     }
    return 0; 
}