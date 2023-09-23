#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    void print(vector<vector<int>> &dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[i].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(1 + word1.size(), vector<int>(1 + word2.size(), 0));
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i < dp[0].size(); i++) {
            dp[0][i] = i;
        }
        for (int i = 0; i < dp.size() - 1; i++) {
            for (int j = 0; j < dp[i].size() - 1; j++) {
                dp[i + 1][j + 1] = word1[i] == word2[j] ? dp[i][j] : (min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j])) + 1);
            }
        }
        print(dp);
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    Solution solution;
    cout << solution.minDistance(a, b) << "\n";
    return 0;
}
