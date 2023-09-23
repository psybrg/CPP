#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
    int uniquePaths(int m, int n){
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c;
    cin >> r >> c;
    Solution solution;
    cout << solution.uniquePaths(r, c) << "\n";
    return 0;
}
/*
f(n,m) = f(n-1,m)+f(n,m-1)
*/