#include <stdio.h>

int gcd(int a, int b) // a = bigger number, b = smaller number
{
    if (b == 0) // If the remainder of the division of the bigger number by smaller number is equal to zero, then return the smaller number as gcd.
    {
        return a;
    } // If a%b == 0 then b will be the last divisor, which is the GCD in euclidean algorithm, which is passed as a in the subsequent call of the function.
    return gcd(b, a % b);
}

int main()
{
    printf("%d", gcd(32, 12));

    return 0;
}