//find minimum of coins to make a given change V
#include<bits/stdc++.h>
using namespace std;
int minCoins(int coins[], int m, int V)
{
    int table[V+1];
    table[0] = 0;
    for (int i=1; i<=V; i++)
        table[i] = INT_MAX;
    for (int i=1; i<=V; i++)
    {
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
            if (table[i-coins[j]] != INT_MAX && table[i-coins[j]] + 1 < table[i])
                table[i] = table[i-coins[j]] + 1;
          }
    }
    return table[V];
}
int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    cout << "Minimum coins required is "
         << minCoins(coins, m, V);
    return 0;
}
