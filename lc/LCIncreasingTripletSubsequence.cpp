#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int p = INT_MAX, q = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= p) {
                p = nums[i];
            } else if (nums[i] <= q) {
                q = nums[i];
            } else
                return true;
        }
        return false;
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
    cout << solution.increasingTriplet(nums) << "\n";
    return 0;
}