#include<bits/stdc++.h> 
using namespace std; 

double f(double x)
{
    return x*x*x - 5*x - 3; 
}

int main()
{
    double x, a = 2, b = 3, abAverage, p, q; 
    int xCount = 0; 
    
    while(xCount <= 20)
    {
    abAverage = (a+b)/2.0; 
    cout << "X" << xCount << " = " << abAverage << " "; 
    cout << "f(" << abAverage  << ") = " << f(abAverage) ; 
    if(f(abAverage) > 0)
    {
        cout << " > 0 and f(" ; 
        if(f(a) < 0 ) { cout << a << ") < 0"; b = abAverage;  }
        else if(f(b) < 0) { cout << b <<  ") < 0"; a = b; }
    }
    else if(f(abAverage) < 0 )
    {
        cout << " < 0 and f(";
        if(f(a) > 0) { cout << a << ") > 0 "; b = a; a = abAverage; }
        else if(f(b) > 0) { cout << b << ") > 0 "; a = abAverage; }
    }

    cout << " Root is between " << a << " and " << b << "\n\n"; 
    xCount++; 
    
    }
   

    return 0; 
}