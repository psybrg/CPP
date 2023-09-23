#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void print(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    int dfs(vector<vector<int> >& grid, int r, int c) {
        if (r >= grid.size()) return c;
        if (c >= 0 && c < grid[0].size() - 1 && grid[r][c] == 1 && grid[r][c + 1] == 1) {
            return dfs(grid, r + 1, c + 1);
        }
        if (c > 0 && c < grid[0].size() && grid[r][c] == -1 && grid[r][c - 1] == -1) {
            return dfs(grid, r + 1, c - 1);
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int> >& grid) {
        vector<int> ans(grid[0].size(), -1);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = dfs(grid, 0, i);
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<vector<int> > nums(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> nums[i][j];
    Solution solution;
    vector<int> ans = solution.findBall(nums);
    solution.print(ans);
    return 0;
}