#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<vector<int> > backtrack(vector<int>& candidates, int target, int index) {
        vector<vector<int> > ans;
        for (int i = index; i < candidates.size(); i++) {
            if (target > candidates[i]) {
                vector<vector<int> > tmp = backtrack(candidates, target - candidates[i], i);
                if (tmp.size() > 0) {
                    for (int j = 0; j < tmp.size(); j++) {
                        tmp[j].push_back(candidates[i]);
                        ans.push_back(tmp[j]);
                    }
                }
            }
            else if (target == candidates[i]) {
                ans.push_back(vector<int>(1, candidates[i]));
            }
        }
        return ans;
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        return backtrack(candidates, target, 0);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<int> nums(r);
    for (int i = 0; i < r; i++) cin >> nums[i];
    Solution solution;
    vector<vector<int> > ans = solution.combinationSum(nums, c);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}
