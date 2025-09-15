#include<bits/stdc++.h>
using namespace std;

int main(){
int n,a,b,c=1,d,e,f;
while(cin>>n){
        if(n==1) cout << 1 << endl;
else {
        vector<int>r;
    for(int i = 2; i<=n;i++) {
      while(n%i==0){
        n/=i;
        r.push_back(i);
      }
    }
    cout << r[0];
f = r[0];
    for(int j = 1;j<r.size();j++){
        if(r[j]==f) ++c;
        else{
            cout << "^" << c << " x " << r[j];
            c = 1;
            f = r[j];
        }
         if(j==r.size()-1){
         cout << "^" << c ;
        }
    }

    cout << endl;
}
}
return 0;
}
