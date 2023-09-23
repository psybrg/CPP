#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int maxArea(vector<int> &height) {
        int lo = 0, hi = height.size() - 1, ans = 0;
        while(lo<hi){
            int h = min(height[hi],height[lo]);
            ans = max(ans, h * (hi - lo));
            while (h >= height[lo] && lo < hi) lo++;
            while (h >= height[hi] && lo < hi) hi--;        
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.maxArea(nums) << "\n";
    return 0;
}
