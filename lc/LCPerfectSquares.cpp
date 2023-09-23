#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<int> dp;
    int numSquares(int n) {
        if (dp.size() < 1) {
            dp.push_back(0);
            dp.push_back(1);
            dp.push_back(2);
            dp.push_back(3);
            dp.push_back(1);
            dp.push_back(2);
            dp.push_back(3);
        }
        if (n == 0) return 1;
        if (n < dp.size()) return dp[n];
        for (int i = dp.size(); i <= n; i++) {
            int j = 2, m = dp[i - 1];
            while (i >= j * j) {
                m = m < dp[i - j * j] ? m : dp[i - j * j];
                j++;
            }
            dp.push_back(1 + m);
        }
        return dp[n];
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Solution solution;
    cout << solution.numSquares(n) << "\n";
    for (int i = 0; i < solution.dp.size(); i++) {
        cout << solution.dp[i] << " ";
    }
    cout << "\n";
    return 0;
}
