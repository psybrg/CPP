#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    queue<pair<int, int> > Q;
    void bfs(int r, int c, vector<vector<int> >& grid) {
        // grid[r][c]++;
        if (r > 0 && grid[r - 1][c] > 0) {
            // grid[r - 1][c]++;
            Q.push(pair<int, int>(r - 1, c));
        }
        if (c > 0 && grid[r][c - 1] > 0) {
            // grid[r][c - 1]++;
            Q.push(pair<int, int>(r, c - 1));
        }
        if (r < grid.size() - 1 && grid[r + 1][c] > 0) {
            // grid[r + 1][c]++;
            Q.push(pair<int, int>(r + 1, c));
        }
        if (c < grid[0].size() - 1 && grid[r][c + 1] > 0) {
            // grid[r][c + 1]++;
            Q.push(pair<int, int>(r, c + 1));
        }
    }
    int numberOfFreshOranges(vector<vector<int> >& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
    int orangesRotting(vector<vector<int> >& grid) {
        int ans = 0, freshOranges1 = -1, freshOranges0 = numberOfFreshOranges(grid);
        while(freshOranges0 != freshOranges1){
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] > 1) {
                        bfs(i, j, grid);
                    }
                }
            }
            while(!Q.empty()) {
                pair<int, int> p = Q.front();
                grid[p.first][p.second]++;
                Q.pop();
            }
            freshOranges1 = freshOranges0;
            freshOranges0 = numberOfFreshOranges(grid);
            ans++;
        }
        return freshOranges0 > 0 ? -1 : ans - 1;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c;
    cin >> r >> c;
    Solution solution;
    vector<vector<int> > grid(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    cout << solution.orangesRotting(grid) << "\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << grid[i][j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}