#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    bool isValid(vector<vector<int> > &grid, int r, int c) {
        return r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size();
    }
    bool allOnes(vector<vector<int> > &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }
    int maxDistance(vector<vector<int> > &grid) {
		if(allOnes(grid)) {
            return -1;
        }
        queue<pair<int, int> > Q;
        vector<pair<int, int> > drxn;
        drxn.push_back(pair<int, int>(1, 0));
        drxn.push_back(pair<int, int>(-1, 0));
        drxn.push_back(pair<int, int>(0, 1));
        drxn.push_back(pair<int, int>(0, -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    Q.push(pair<int, int>(i, j));
                }
            }
        }
        while (!Q.empty()) {
            pair<int, int> p = Q.front();
            Q.pop();
            for (int i = 0; i < drxn.size(); i++) {
                int r = p.first + drxn[i].first;
                int c = p.second + drxn[i].second;
                if (isValid(grid, r, c)) {
                    if (grid[r][c] < 1) {
                        grid[r][c] = 1 + grid[p.first][p.second];
                        Q.push(pair<int, int>(r, c));
                    }
                }
            }
        }
        int mx = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                mx = max(mx, grid[i][j]);
            }
        }
        return mx - 1;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<vector<int> > nums(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> nums[i][j];
    Solution solution;
    cout << solution.maxDistance(nums) << "\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << nums[i][j] << "\t";
        cout << "\n";
    }
    return 0;
}