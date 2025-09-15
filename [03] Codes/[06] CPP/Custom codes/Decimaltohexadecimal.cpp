#include<iostream>
#include<math.h>
using namespace std;

string dec_hex(long long int n)
{
    string digit = "0123456789ABCDEF";
    string hex;
 do
 {
    hex=digit[n%16]+hex;
    n/=16;
 } while(n!=0);

 return hex;
}

long long int hex_dec(string s)
{
    long long int dec = 0;
  int j[200];
  j['0'] = 0;
  j['1'] = 1;
  j['2'] = 2;
  j['3'] = 3;
  j['4'] = 4;
  j['5'] = 5;
  j['6'] = 6;
  j['7'] = 7;
  j['8'] = 8;
  j['9'] = 9;
  j['A'] = 10;
  j['B'] = 11;
  j['C'] = 12;
  j['D'] = 13 ;
  j['E'] = 14;
  j['F'] = 15;

  for(int i = s.size()-1,k = 0; i>=0; i--,k++)
  {
      dec+= pow(16,k)*j[s[i]];
  }
  return dec;
}

int main()
{
  for(int i = 0; i<101; i++){
    cout << dec_hex(i) << " -> " << hex_dec(dec_hex(i)) << endl;
  }
    return 0;
}
