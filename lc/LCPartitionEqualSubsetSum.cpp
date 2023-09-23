#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void print(vector<bool>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << "\t";
        }
        cout << "\n";
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1 || nums.size() < 2) return false;
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = dp.size() - 1; j >= nums[i]; j--) {
                if (dp[j - nums[i]]) {
                    dp[j] = true;
                }
            }
        }
        print(dp);
        return dp[sum];
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
    cout << solution.canPartition(nums) << "\n";
    return 0;
}