#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    static bool compare(vector<int>& left, vector<int>& right) {
        return left[0] != right[0] ? left[0] < right[0] : left[1] < right[1];
    };
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int> > ans;
        vector<int> row = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (row[1] >= intervals[i][0]) {
                row[0] = min(row[0], intervals[i][0]);
                row[1] = max(row[1], intervals[i][1]);
            } else {
                ans.push_back(row);
                row = intervals[i];
            }
        }
        ans.push_back(row);
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c = 2;
    cin >> r;
    vector<vector<int> > matrix(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> matrix[i][j];
    Solution solution;
    vector<vector<int> > intervals = solution.merge(matrix);
    for (int i = 0; i < intervals.size(); i++) {
        cout << intervals[i][0] << "\t" << intervals[i][1] << "\n";
    }
    return 0;
}
