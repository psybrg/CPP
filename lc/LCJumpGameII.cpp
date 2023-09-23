#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int max(int a, int b) { return a > b ? a : b; }
    int jump(vector<int>& nums) {
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur = max(cur, nums[i]);
            nums[i] = cur;
            cur--;
        }
        int ans = 0;
        cur = 0;
        while (cur < nums.size() - 1) {
            if (nums[cur] < 1) return -1;
            cur += nums[cur];
            ans++;
        }
        return ans;
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
    cout << solution.jump(nums) << "\n";
    return 0;
}