#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void print(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    void reverse(vector<int>& nums, int lo, int hi) {
        if (lo < 0) lo = 0;
        if (hi >= nums.size()) hi = nums.size() - 1;
        while (lo < hi) {
            int t = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = t;
            lo++;
            hi--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        int lo = nums.size() - 1;
        while (lo > 0) {
            if (nums[lo] <= nums[lo - 1]) {
                lo--;
            } else
                break;
        }
        lo--;
        if (lo >= 0) {
            int hi = nums.size() - 1;
            while (nums[hi] <= nums[lo]) {
                hi--;
            }
            int t = nums[lo];
            nums[lo] = nums[hi];
            nums[hi] = t;
            reverse(nums, lo + 1, nums.size() - 1);
        } else {
            reverse(nums, 0, nums.size() - 1);
        }
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    solution.nextPermutation(nums);
    solution.print(nums);
    return 0;
}