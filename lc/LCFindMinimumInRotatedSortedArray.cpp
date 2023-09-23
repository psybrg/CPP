#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int m0 = (lo + hi) / 2;
            if (nums[lo] < nums[hi]) {
                return nums[lo];
            }
			if (nums[m0] >= nums[lo]) {
				lo = m0 + 1;
			} else {
				hi = m0;
			}
            cout << m0 << "\n";
        }
        return nums[lo];
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
    cout << solution.findMin(nums) << "\n";
    return 0;
}