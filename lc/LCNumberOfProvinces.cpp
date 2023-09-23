#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int mag(int x) { return x > 0 ? x : -x; }
    void dfs(int v, vector<vector<int> > &isConnected, vector<bool> &visited) {
        visited[v] = true;
        for (int i = 0; i < isConnected[v].size(); i++) {
            if (isConnected[v][i] && v != i && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int> > &isConnected) {
        int ans = 0;
        vector<bool> visited(isConnected.size(), false);
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                ans++;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r;
    cin >> r;
    Solution solution;
    vector<vector<int> > grid(r, vector<int>(r, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            cin >> grid[i][j];
        }
    }
    cout << solution.findCircleNum(grid) << "\n";
    return 0;
}