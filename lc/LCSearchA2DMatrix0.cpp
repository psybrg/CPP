#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool binarySearch(vector<int>& v, int k) {
        int lo = 0, hi = v.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            cout << lo << "\t" << mid << "\t" << hi << "\n";
            if (v[mid] > k) {
                hi = mid - 1;
            } else if (v[mid] < k) {
                lo = mid + 1;
            } else {
                return true;
            }
        }
        return v[lo] == k;
    }
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if (binarySearch(matrix[i], target)) {
                return true;
            }
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
