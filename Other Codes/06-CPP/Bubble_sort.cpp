#include <bits/stdc++.h>
using namespace std;
int numberArray[10] = {23, 234, 11, 1553, 112, 90, 71, 67, 89, 90};
int main()
{
    for (int i = 9; i >= 0; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (numberArray[i] < numberArray[j])
            {
                int temp = numberArray[i];
                numberArray[i] = numberArray[j];
                numberArray[j] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << numberArray[i] << " ";
    }
}