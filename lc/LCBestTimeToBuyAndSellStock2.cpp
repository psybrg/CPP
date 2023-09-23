#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
    int max(int a, int b){
        return a > b ? a : b;
    }
    int maxProfit(vector<int> &prices){
        vector<vector<int> > dp(2, vector<int>(prices.size(), 0));
        dp[1][0] = -prices[0];
        cout << dp[0][0] << "\t" << dp[1][0] << "\n";
        for (int i = 1; i < prices.size(); i++){
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]);
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            cout << dp[0][i] << "\t" << dp[1][i] << "\n";
        }
        return max(dp[1][prices.size() - 1], dp[0][prices.size() - 1]);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    Solution solution;
    cout << solution.maxProfit(prices) << "\n";
    return 0;
}

/*
f(n, 0) = f(n-1,0), f(n-1,1) - a[n]
f(n, 1) = f(n-1,1), f(n-1,0) + a[n]

/**/