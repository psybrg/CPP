#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void print2D(vector<vector<int> > &nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                cout << nums[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    bool isValid(vector<vector<int> > &graph, int r, int c) {
        return r >= 0 && c >= 0 && r < graph.size() && c < graph[0].size();
    }

    vector<vector<int> > drxns;

    void dfs(vector<vector<int> > &graph, vector<vector<int> > &visited, int r, int c, int t) {
        if (isValid(graph, r, c)) {
            visited[r][c] += t;
            for (int i = 0; i < drxns.size(); i++) {
                int x = r + drxns[i][0];
                int y = c + drxns[i][1];
                if (isValid(graph, x, y) && visited[x][y] < t && graph[r][c] <= graph[x][y]) {
                    dfs(graph, visited, x, y, t);
                }
            }
        }
    }

    vector<vector<int> > pacificAtlantic(vector<vector<int> > &heights) {
        int drxn[] = {0, -1};
        drxns.push_back(vector<int>(drxn, drxn + sizeof drxn / sizeof drxn[0]));
        drxn[1] = 1;
        drxns.push_back(vector<int>(drxn, drxn + sizeof drxn / sizeof drxn[0]));
        drxn[0] = 1;
        drxn[1] = 0;
        drxns.push_back(vector<int>(drxn, drxn + sizeof drxn / sizeof drxn[0]));
        drxn[0] = -1;
        drxns.push_back(vector<int>(drxn, drxn + sizeof drxn / sizeof drxn[0]));
        vector<vector<int> > visited(heights.size(), vector<int>(heights[0].size(), 0));
        for (int i = 0; i < visited[0].size(); i++) {
            if (visited[0][i] < 1) {
                dfs(heights, visited, 0, i, 1);
            }
        }
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i][0] < 1) {
                dfs(heights, visited, i, 0, 1);
            }
        }
        for (int i = 0; i < visited[0].size(); i++) {
            if (visited[visited.size() - 1][i] < 2) {
                dfs(heights, visited, visited.size() - 1, i, 2);
            }
        }
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i][visited[0].size() - 1] < 2) {
                dfs(heights, visited, i, visited[0].size() - 1, 2);
            }
        }
        print2D(visited);
        vector<vector<int> > ans;
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[0].size(); j++) {
                if (visited[i][j] > 2) {
                    int vec[] = {i, j};
                    ans.push_back(vector<int>(vec, vec + sizeof vec / sizeof vec[0]));
                }
            }
        }
        return ans;
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
    vector<vector<int> > ans = solution.pacificAtlantic(nums);
    solution.print2D(ans);
    return 0;
}

/*

5
5
1 2 2 3 5
3 2 3 4 4
2 4 5 3 1
6 7 1 4 5
5 1 1 2 4


3 2
1 1 1 1 1 1

[[1,1],[1,1],[1,1]]
*/