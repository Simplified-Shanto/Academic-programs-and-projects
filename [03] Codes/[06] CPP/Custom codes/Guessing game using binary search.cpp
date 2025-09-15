#include<bits/stdc++.h>
using namespace std;

int main(){
    int high= 1000000, low = 0, mid = (high+low)/2;
    cout << "Is the number " << mid << " ?" << endl;

    string a;
    cin >> a;
    while(a!="yes"){
     mid = (high+low)/2;
     cout << "Is the number " << mid << " ?" << endl;
     cin >> a;
     if(a=="more") { low = mid;}
     else if(a=="less") {high = mid;}
    }


return 0;
}
