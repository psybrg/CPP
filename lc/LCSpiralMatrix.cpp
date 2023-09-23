#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool isValidRight(int row, int col, vector<vector<int> >& matrix) {
        return col + 1 < matrix[0].size();
    }
    bool isValidLeft(int row, int col, vector<vector<int> >& matrix) {
        return col >= 1;
    }
    bool isValidDown(int row, int col, vector<vector<int> >& matrix) {
        return row + 1 < matrix.size();
    }
    bool isValidUp(int row, int col, vector<vector<int> >& matrix) {
        return row >= 1;
    }
    vector<int> spiralOrder(vector<vector<int> >& matrix, int k) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return vector<int>(0);
        vector<int> ans;
        int row = 0, col = 0, rc = matrix.size() * matrix[0].size();
        while (rc > 0) {
            ans.push_back(matrix[row][col]);
            matrix[row][col] += 1000;
            if (isValidRight(row, col, matrix) && matrix[row][col + 1] <= 100 &&
                matrix[row][col + 1] >= -100) {
                col++;
            } else if (isValidDown(row, col, matrix) &&
                       matrix[row + 1][col] <= 100 &&
                       matrix[row + 1][col] >= -100) {
                row++;
            } else if (isValidLeft(row, col, matrix) &&
                       matrix[row][col - 1] <= 100 &&
                       matrix[row][col - 1] >= -100) {
                col--;
            } else if (isValidUp(row, col, matrix) &&
                       matrix[row - 1][col] <= 100 &&
                       matrix[row - 1][col] >= -100) {
                row--;
            } else {
                break;
            }
            rc--;
        }
        return ans;
    }
    vector<int> spiralOrder(vector<vector<int> >& matrix, char c) {
        if (matrix.size() < 1 || matrix[0].size() < 1) return vector<int>(0);
        vector<int> ans;
        int z = (min(matrix.size(), matrix[0].size())) / 2;
        int x = matrix[0].size() - 1;
        int y = matrix.size() - 1;
        for (int i = 0; i < z; i++) {
            cout << x << "\t" << y << "\n";
            for (int j = 0; j < x; j++) {
                ans.push_back(matrix[i][i + j]);
                cout << ans[ans.size() - 1] << "\t";
            }
            cout << "\n";
            for (int j = 0; j < y; j++) {
                ans.push_back(matrix[i + j][matrix[0].size() - 1 - i]);
                cout << ans[ans.size() - 1] << "\t";
            }
            cout << "\n";
            for (int j = 0; j < x; j++) {
                ans.push_back(matrix[matrix.size() - 1 - i]
                                    [matrix[0].size() - 1 - i - j]);
                cout << ans[ans.size() - 1] << "\t";
            }
            cout << "\n";
            for (int j = 0; j < y; j++) {
                ans.push_back(matrix[matrix.size() - 1 - j][i]);
                cout << ans[ans.size() - 1] << "\t";
            }
            cout << "\n";
            x -= 2;
            y -= 2;
        }
        if (matrix.size() % 2 == 1 && matrix[0].size() % 2 == 1) {
            if (x > y) {
                for (int i = z; i < matrix[0].size() - z; i++) {
                    ans.push_back(matrix[matrix.size() / 2][i]);
                }
            } else {
                for (int i = z; i < matrix.size() - z; i++) {
                    ans.push_back(matrix[i][matrix[0].size() / 2]);
                }
            }
        }
        return ans;
    }
    bool isValidMove(int x, int y, vector<vector<int> >& grid){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }
    int mag(int z) { return z > 0 ? z : -z; }
    vector<int> spiralOrder(vector<vector<int> >& matrix){
        vector<int> ans;
        int rows = matrix.size(), cols = matrix[0].size(), x = 0, y = 1;
        int row = 0, col = -1, dx = matrix[0].size(), dy = matrix.size() - 1;
        int rc = rows * cols, moves = dx;
        while(rc>0){
            while(isValidMove(row + x, col + y, matrix) && moves > 0){
                row += x;
                col += y;
                ans.push_back(matrix[row][col]);
                moves--;
                cout << matrix[row][col] << "\t";
                rc--;
            }
            cout << "\n";
            moves = mag(dx * x + dy * y);
            int t = x;
            x = y;
            y = -t;
            dx -= mag(x);
            dy -= mag(y);
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > nums(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++) cin >> nums[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) cout << nums[i][j] << "\t";
        cout << "\n";
    }
    Solution solution;
    vector<int> ans = solution.spiralOrder(nums);
    cout << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << "\n";
    return 0;
}