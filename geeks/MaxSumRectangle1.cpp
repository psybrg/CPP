#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    /*
    Time Complexity : O(n^3)
    Memory Complexity : O(n^2)
    */
    int kadane(vector<int> &arr) {
        int mx = arr[0], s = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            s = max(s + arr[i], arr[i]);
            mx = max(s, mx);
        }
        return mx;
    }
    int maxSumRectangle(vector<vector<int>> grid) {
        int mx = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            vector<int> row = grid[i];
            for (int j = i; j < grid.size(); j++) {
                if (i < j) {
                    for (int k = 0; k < grid[i].size(); k++) {
                        row[k] += grid[j][k];
                    }
                }
                mx = max(mx, kadane(row));
            }
        }
        return mx;
    }
};
int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll r, c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }
        Solution sol;
        cout << sol.maxSumRectangle(grid) << "\c";
    }
    return 0;
}