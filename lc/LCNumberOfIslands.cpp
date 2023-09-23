#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int mag(int x) { return x > 0 ? x : -x; }
    void bfs(int r, int c, vector<string>& grid) {
        queue<pair<int, int> > Q;
        Q.push(pair<int, int>(r, c));
        grid[r][c]--;
        // cout << r << "\t" << c << "\n";
        while (!Q.empty()) {
            pair<int, int> p = Q.front();
            Q.pop();
            for (int x = -1; x < 2; x++) {
                for (int y = -1; y < 2; y++) {
                    if (mag(x) != mag(y) && (x + p.first) >= 0 && (y + p.second) >= 0 && (x + p.first) < grid.size() && (y + p.second) < grid[p.first].size() && grid[p.first + x][p.second + y] == '1') {
                        // cout << p.first + x << "\t" << p.second + y << "\n";
                        Q.push(pair<int, int>(p.first + x, p.second + y));
                        grid[p.first + x][p.second + y]--;
                    }
                }
            }
        }
    }
    int numIslands(vector<string>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r;
    cin >> r;
    Solution solution;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        cin >> grid[i];
    }
    cout << solution.numIslands(grid) << "\n";
    for (int i = 0; i < r; i++) {
        cout << grid[i] << "\n";
    }
    return 0;
}