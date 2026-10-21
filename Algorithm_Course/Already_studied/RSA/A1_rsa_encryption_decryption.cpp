#include <iostream>
#include<cmath> 

using namespace std;


long long gcd(long long a, long long b)
{
    if(b==0) return a; 
    return gcd(b, a%b); 
}


long long powerMod(long long base, long long exponent, long long modulus)
{
    long long result = 1; 

    // Keep the base small from the beginning. 
    base = base % modulus; // when a mod n = r, then a^exponent mod n = r^exponent mod n ,,, Same remainder after exponentiation modulo modulus, so exponent stays unchanged.

    while(exponent > 0){
        if(exponent %2 == 1){ // , An odd exponent means its current binary bit is 1
            result = (result*base) % modulus; //That exponent has decreased by 1 and now is even
        }

        // Move from base^(2^k) to base^(2^(k+1)).
        base = (base * base) %modulus; 

        // Move to the next binary bit. 
        exponent = exponent /2; 
    }
    return result; 
}

/*
Trace for powerMod(65, 17, 3233):

Loop | exponent | exponent odd? | result after possible multiplication | base for next loop
-----|----------|---------------|------------------------------------|-------------------
Start|    17    |       --      | 1                                  | 65
1    |    17    |      Yes      | (1 * 65) % 3233 = 65              | 65^2 % 3233 = 992
2    |     8    |      No       | 65                                 | 992^2 % 3233 = 1232
3    |     4    |      No       | 65                                 | 1232^2 % 3233 = 1547
4    |     2    |      No       | 65                                 | 1547^2 % 3233 = 789
5    |     1    |      Yes      | (65 * 789) % 3233 = 2790          | Not needed

17 in binary is 10001, so only powers 65^16 and 65^1 are multiplied:
65^17 % 3233 = (65^16 * 65^1) % 3233 = (789 * 65) % 3233 = 2790.
*/

int main() {
    // Fixed small prime numbers for lab practice. Real RSA uses very large primes.
    long long p = 61;
    long long q = 53;

    // Public exponent and the integer message to encrypt.
    long long e = 17;
    long long M = 65; // M = message 

   
    // Next: find d so that (e * d) % phi == 1.
    // Then encrypt: encryptedMessage = message^e mod n.
    // Finally decrypt: decryptedMessage = encryptedMessage^d mod n.

    long long n = p*q; 
    long long phi = (p-1)*(q-1); 

    cout << "Public key (e, n) is (" << e  << ", " << n << ")" << endl; 


    long long x = 1; 
    while((phi*x + 1)%e!=0) x++; 
    long long d = (phi*x + 1)/e; 
    cout << "Private exponent d is " << d << endl; 


    long long C = powerMod(M, e, n); 
    cout << "Encrypted Message: " << C << endl; 

    long long decipheredM = powerMod(C, d, n); 
    cout << "Decrypted Message: " << decipheredM << endl; 
    return 0;
}
