#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            int x = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j] && dp[i - coins[j]] >= 0) {
                    x = min(x, dp[i - coins[j]]);
                }
            }
            if (x != INT_MAX) {
                dp[i] = 1 + x;
            }
        }
        return dp[amount];
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    Solution solution;
    cout << solution.coinChange(coins, k) << "\n";
    return 0;
}
/*
f(i) = 1 + min (f ( i - coins[0 : c] ))
*/