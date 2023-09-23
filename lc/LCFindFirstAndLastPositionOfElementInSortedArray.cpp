#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.size() < 1) return ans;
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (lo < nums.size() && target == nums[lo]) {
            ans[0] = lo;
        }
        lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = 1 + lo + (hi - lo) / 2;
            if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                lo = mid;
            }
        }
        if (lo < nums.size() && target == nums[lo]) {
            ans[1] = lo;
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
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    Solution solution;
    vector<int> ans = solution.searchRange(coins, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << "\n";
    return 0;
}