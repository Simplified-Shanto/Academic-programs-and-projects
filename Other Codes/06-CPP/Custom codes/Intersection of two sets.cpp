#include<bits/stdc++.h>
using namespace std;

int main(){

 int a,b,c,d,e,f;
 char i;
 unordered_set<int> set1;
 unordered_set<int> set2;
 unordered_set<int> set3;

 cin >> a;
 while(a--) {
    cin >> d; set1.insert(d);
 }
 cin >> a;
 while(a--){
    cin >> d; set2.insert(d);
 }
   for(auto x:set1){
  if(set2.count(x)==1) set3.insert(x);
   }

   if(set3.size()==0) cout << "No element found in common: Inputted sets are disjoint\n";
   else {
    cout << "Elements found in common: ";
     for(auto x :set3) cout << x << " " ;
   cout << endl;
   }


return 0;
}
