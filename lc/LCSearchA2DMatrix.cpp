#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix[0].size() < 1 || matrix.size() < 1) return false;
        int x = 0, y = matrix[0].size() - 1;
        while (x < matrix.size() && y >= 0) {
            cout << x << "\t" << y << "\n";
            if (target > matrix[x][y])
                x++;
            else if (target < matrix[x][y])
                y--;
            else
                return true;
            cout << x << "\t" << y << "\n";
        }
        return false;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c, k;
    cin >> r >> c;
    vector<vector<int> > matrix(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> matrix[i][j];
    cin >> k;
    Solution solution;
    cout << solution.searchMatrix(matrix, k) << "\n";
    return 0;
}
