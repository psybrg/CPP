#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        set<int> numss;
        for (int i = 0; i < nums.size(); i++) {
            numss.insert(nums[i]);
        }
        auto qtr = numss.begin();
        qtr++;
        int s = 1, ans = 1;
        for (auto ptr = numss.begin(); ptr != numss.end() && qtr != numss.end();
             ptr++, qtr++) {
            if((*ptr+1)==*qtr){
                s++;
            } else {
                s = 1;
            }
            ans = ans > s ? ans : s;
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
    cout << solution.longestConsecutive(nums) << "\n";
    return 0;
}
