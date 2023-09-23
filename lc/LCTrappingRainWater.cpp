#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int trap(vector<int> &heights) {
        stack<int> stk;
        int sum = 0, curr = 0, idx = heights.size() - 1;
        for (int i = 0; i < heights.size(); i++) {
            if (stk.empty() || stk.top() <= heights[i]) {
                if (!stk.empty()) {
                    stk.pop();
                }
                stk.push(heights[i]);
                idx = i;
                sum += curr;
                curr = 0;
            } else {
                curr += stk.top() - heights[i];
            }
        }
        curr = 0;
        while (!stk.empty()) {
            stk.pop();
        }
        // cout << idx << "\n";
        for (int i = heights.size() - 1; i >= idx; i--) {
            if (stk.empty() || stk.top() < heights[i]) {
                if (!stk.empty()) {
                    stk.pop();
                }
                stk.push(heights[i]);
                sum += curr;
                curr = 0;
            } else {
                curr += stk.top() - heights[i];
            }
            // cout << i << "\t" << heights[i] << "\n";
        }
        return sum;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution solution;
    cout << solution.trap(nums) << "\n";
    return 0;
}