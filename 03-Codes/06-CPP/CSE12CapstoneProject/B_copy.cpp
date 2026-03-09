#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    
    int n;
    cin >> n;
    vector<int> prices(100001, 0);

    for (int i = 0; i < n; i++)
    {
        int price;
        cin >> price;
        prices[price]++;
    }

    map<int, int> uniquePrices;
    for (int i = 0; i <= 100001; i++)
    {
        if (prices[i] != 0)
        {
            uniquePrices.insert({i, prices[i]}); // i = a particular price, prices[i] = number of occurrence of shop with that price
        }
    }

    int pos = 0;
    for (auto it = uniquePrices.begin(); it != uniquePrices.end(); ++it, ++pos)
    {
        if (pos == 0)
            continue; // we want to start from index 1
        auto prevIt = prev(it);
        it->second += prevIt->second;
    }

    int dayCount;
    cin >> dayCount;

    vector<pair<int, int>> spendableCoins;
    for (int i = 1; i <= dayCount; i++)
    {
        int coins;
        cin >> coins;
        spendableCoins.push_back({i, coins});
    }

    stable_sort(spendableCoins.begin(), spendableCoins.end(), [](const pair<int, int> &a, const pair<int, int> &b)
                { return a.second < b.second; });

    auto it = uniquePrices.begin();
    for (int i = 0; i < dayCount; i++)
    {
        while (spendableCoins[i].second >= it->first && it != uniquePrices.end())
        {
            it = next(it);
        }
        if (it == uniquePrices.begin()) // Minimum price is greater than the spendable coins for the ith day
        {
            spendableCoins[i].second = 0;
        }
        else
        {
            auto it2 = prev(it); // pointer to the last element of the map
            spendableCoins[i].second = it2->second;
        }
    }

    stable_sort(spendableCoins.begin(), spendableCoins.end(), [](const pair<int, int> &a, const pair<int, int> &b)
                { return a.first < b.first; });

    for (int i = 0; i < dayCount; i++)
    {
        cout << spendableCoins[i].second << endl;
    }

    return 0;
}
