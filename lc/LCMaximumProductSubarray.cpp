#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int smx = nums[0], ans = nums[0], smn = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int mn = smn, mx = smx;
            smx = max(nums[i], nums[i] * (nums[i] >= 0 ? mx : mn));
            smn = min(nums[i], nums[i] * (nums[i] >= 0 ? mn : mx));
            ans = max(ans, max(smx, smn));
        }
        return ans;
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
    cout << solution.maxSubArray(nums) << "\n";
    return 0;
}
