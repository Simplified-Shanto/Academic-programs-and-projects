#include <stdio.h>

int gcd(int a, int b) // a = bigger number, b = smaller number
{
    if (b == 0)
    {
        return a;  // In this condition, b is the last remainder which is 0 and a is that last divisor. 
    } // If a%b == 0 then b will be the last divisor, which is the GCD in euclidean algorithm, which is passed as a in the subsequent call of the function.
    return gcd(b, a % b);  // b is the new dividend, and a%b is the new divisor. 
}

int main()
{
    printf("%d", gcd(32, 12));

    return 0;
}