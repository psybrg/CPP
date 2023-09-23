#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (x <= 0) return false;
            x--;
            x = max(x, nums[i]);
        }
        return true;
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
    cout << solution.canJump(nums) << "\n";
    return 0;
}