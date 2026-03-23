//Fibonacci series using recursion
#include <iostream>
using namespace std;

int fib (int n);

int main()
{
    int n, answer;
    cout << "Enter number to find: ";
    cin >> n;
    cout << "\n\n";

    answer = fib(n);

    cout << answer << " is the " << n;
    cout << "th Fibonacci number\n";

getchar();
    return 0;
    
}

int fib (int n)
{
    cout << "Processing fib(" << n << ")...";

    if(n<3)
    {
        cout << "Return 1!\n";
        return (1);
    }
    else
    {
        cout << "Call fib(" << n-2 << ") ";
        cout << "and fib(" << n-1 << ").\n";
        return(fib(n-2) + fib(n-1));
    }
}