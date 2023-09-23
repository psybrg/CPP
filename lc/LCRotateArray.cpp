#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void rotate0(vector<int>& nums, int k) {
        int idx = 0, mem = nums[0];
        // k = nums.size() - k;
        for (int i = 0; i < nums.size(); i++) {
            nums[(idx + k) % nums.size()] = nums[idx];
            idx = (idx + k) % nums.size();
        }
    }
    void reverse(vector<int>& nums, int lo, int hi) {
        while (0 <= lo && lo < hi && hi < nums.size()) {
            int t = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = t;
            lo++;
            hi--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1 - k);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    cin >> k;
    Solution solution;
    solution.rotate(coins, k);
    for (int i = 0; i < n; i++) cout << coins[i] << "\t";
    cout << "\n";
    return 0;
}
