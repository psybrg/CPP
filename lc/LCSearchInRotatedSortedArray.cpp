#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            cout << lo << "\t" << hi << "\n";
            int mid = (lo + hi) / 2;
            if (nums[lo] <= nums[hi]) {
                if (target > nums[mid]) {
                    lo = mid + 1;
                } else if (target < nums[mid]) {
                    hi = mid - 1;
                } else
                    return mid;
            } else {
                if (target == nums[lo]) return lo;
                if (target == nums[mid]) return mid;
                if (target == nums[hi]) return hi;
                if (nums[lo] < target && nums[mid] > target) {
                    hi = mid - 1;
                } else if (nums[mid] < target && nums[hi] > target) {
                    lo = mid + 1;
                } else if (nums[lo] < nums[mid] && nums[lo] != target &&
                           nums[mid] != target) {
                    lo = mid + 1;
                } else if (nums[mid] < nums[hi] && nums[hi] != target &&
                           nums[mid] != target) {
                    hi = mid - 1;
                } else if (nums[lo] > nums[mid]) {
                    hi = mid - 1;
                } else if (nums[mid] > nums[hi]) {
                    lo = mid + 1;
                }
            }
        }
        if (target == nums[lo]) return lo;
        return -1;
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
    cin >> k;
    Solution solution;
    cout << solution.search(nums, k) << "\n";
    return 0;
}