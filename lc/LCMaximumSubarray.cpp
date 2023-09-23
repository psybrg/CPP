#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int max(int a, int b) { return a > b ? a : b; }
    int maxSubArray(vector<int>& nums) {
        int s = nums[0], mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            s = max(nums[i], s + nums[i]);
            mx = max(s, mx);
        }
        return mx;
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
