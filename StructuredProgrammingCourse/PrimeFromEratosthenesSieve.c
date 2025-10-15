#include<stdio.h> 

int main()
{
    int n = 1000; 
    int prime[n+1];
    prime[0] = 0;
    prime[1] = 0; 
    for (int i = 2; i <=n; i++)
    {
        prime[i] = 1; 
    }

    for (int p = 2; p * p <= n; p++) // We are only checking upto square root of n because, checking for some p greater than square root of n will result (n/p) value smaller than p which is already checked. 
    {
        if(prime[p]==1)
        {
            for (int i = p * p; i <= n; i+=p) // We are starting from p * p rather than p*(2, 3, 4 ... p-1) because the multiples of 2, 3, 4 ... p-1 has already been flagged as non-prime. 
            {
                prime[i] = 0; 
            }
        }
    }

    printf("Prime numbers in the given range are: \n");
    for (int i = 2; i <= n; i++)
    {
        if(prime[i]==1)
            printf("%d ", i); 
    }
}