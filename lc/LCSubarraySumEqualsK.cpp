#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int sum = 0, ans = 0;
        mp[sum] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.subarraySum(nums, k) << "\n";
    return 0;
}