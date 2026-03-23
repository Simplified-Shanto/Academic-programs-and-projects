#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, lb = -2*1000000000, ub = -lb;
    cin >> n;
    while (n--)
    {
        string comp;
        char ans;
        int value;
        cin >> comp >> value >> ans;

        if ((comp == ">" && ans == 'Y') || (comp == "<=" && ans == 'N'))
        {
            lb = max(lb, value + 1);
        }
        else if ((comp == ">=" && ans == 'Y') || (comp == "<" && ans == 'N'))
        {
            lb = max(lb, value);
        }
        else if ((comp == "<" && ans == 'Y') || (comp == ">=" && ans == 'N'))
        {
            ub = min(ub, value - 1);
        }
        else if ((comp == "<=" && ans == 'Y') || (comp == ">" && ans == 'N'))
        {
            ub = min(ub, value);
        }
    }

    if (lb <= ub)
    {
        cout << lb << endl;
    }
    else
    {
        cout << "Impossible";
    }

    return 0;
}