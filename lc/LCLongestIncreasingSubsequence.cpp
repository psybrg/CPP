#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int longestIncreasingSubsequence(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                }
            }
            ans = ans > dp[i] ? ans : dp[i];
        }
        for (int i = 0; i < dp.size(); i++) cout << dp[i] << " ";
        cout << "\n";
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.longestIncreasingSubsequence(nums) << "\n";
    return 0;
}

/*

f(i)=1+max(f(0->i-1))

*/