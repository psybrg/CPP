#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int kthSmallestElement(vector<vector<int> > &matrix, int k) {
        for (int i = 1; i < matrix.size(); i++) {
            vector<int> v;
            for (int j = 0; j < i; j++) {
                    v.push_back(matrix[j][i]);
                    v.push_back(matrix[i][j]);
            }
            sort(v.begin(), v.end());
            for (int j = 0; j < i; j++){
                matrix[j][i] = v[j];
                matrix[i][j] = v[i + j];
            }
        }
        return matrix[(k - 1) / matrix.size()][(k - 1) % matrix.size()];
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
    Solution solution;
    cout << solution.kthSmallestElement(matrix, k) << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << matrix[i][j] << " ";
        cout << "\n";
    }
    return 0;
}