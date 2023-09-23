#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int minPathSum(vector<vector<int> >& grid) {
        for (int i = 1; i < grid.size(); i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < grid[0].size(); i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[i].size(); j++) {
                grid[i][j] += min(i > 0 ? grid[i - 1][j] : INT_MAX, j > 0 ? grid[i][j - 1] : INT_MAX);
            }
        }
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid[i].size(); j++) 
        //         cout << grid[i][j] << "\t";
        //     cout << "\n";
        // }
        return grid[grid.size() - 1][grid[0].size() - 1];
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
    cout << solution.minPathSum(nums) << "\n";
    return 0;
}