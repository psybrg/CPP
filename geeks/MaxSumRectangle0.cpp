#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    /*
    Time Complexity : O(n^4)
    Memory Complexity : O(n^2)
    */
    int maxSumRectangle(vector<vector<int>> grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> preSum(r + 1, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                preSum[i + 1][j] = preSum[i][j] + grid[i][j];
            }
        }
        int maxSum = -1;
        int minSum = INT_MIN;
        int negRow = 0, negCol = 0;
        int rStart = 0, rEnd = 0, cStart = 0, cEnd = 0;
        for (int rowStart = 0; rowStart < r; rowStart++) {
            for (int row = rowStart; row < r; row++) {
                int sum = 0;
                int curColStart = 0;
                for (int col = 0; col < c; col++) {
                    sum += preSum[row + 1][col] - preSum[rowStart][col];
                    if (sum < 0) {
                        if (minSum < sum) {
                            minSum = sum;
                            negRow = row;
                            negCol = col;
                        }
                        sum = 0;
                        curColStart = col + 1;
                    } else if (maxSum < sum) {
                        maxSum = sum;
                        rStart = rowStart;
                        rEnd = row;
                        cStart = curColStart;
                        cEnd = col;
                    }
                }
            }
        }
        // Printing final values
        if (maxSum == -1) {
            cout << "from row - " << negRow << " to row - " << negRow;
            cout << "from col - " << negCol << " to col - " << negCol;
        } else {
            cout << "from row - " << rStart << " to row - " << rEnd;
            cout << "from col - " << cStart << " to col - " << cEnd;
        }
        return maxSum == -1 ? minSum : maxSum;
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