#include<iostream> 
using namespace std; 

int main()
{
    double a = 11, b = 6; 
    for(int i = 2; ;i++ )
    {
        a+=5; 
        b*=1.4; 
        cout << "Year " << i << " a  = " << a << " b = " << b << "\n"; 
        if(b>a) {cout << i << "\n"; return 0 ; }
    }
}