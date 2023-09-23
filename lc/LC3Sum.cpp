#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            if (target < 0) break;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else {
                    ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l] == nums[l + 1]) l++;
                    while (l < r - 1 && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
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
    vector<vector<int> > ans = solution.threeSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}