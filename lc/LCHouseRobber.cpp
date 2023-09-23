#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[dp.size() - 1] > dp[dp.size() - 2] ? dp[dp.size() - 1]
                                                     : dp[dp.size() - 2];
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.rob(nums) << "\n";
    return 0;
}
/*
f(i)=max(f(i-1), a[i]+f(i-2))
*/