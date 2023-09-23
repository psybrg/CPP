#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        multiset<int, greater<int> > window;
        vector<int> ans;
        for (int i = 0; i < k && i < nums.size(); i++) {
            window.insert(nums[i]);
        }
        ans.push_back(*(window.begin()));
        for (int i = k, j = 0; i < nums.size(); i++, j++) {
            window.insert(nums[i]);
            window.erase(window.find(nums[j]));
            ans.push_back(*(window.begin()));
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    Solution solution;
    vector<int> ans = solution.maxSlidingWindow(coins, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << "\n";
    return 0;
}