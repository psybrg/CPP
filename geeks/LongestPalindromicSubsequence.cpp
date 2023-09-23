#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    public:
    int longestPalinSubseq(string A) {
        string B = A;
        for (int i = 0; i < A.size(); i++) {
            B[i] = A[A.size() - 1 - i];
        }
        vector<vector<int>> dp(A.size() + 1, vector<int>(A.size() + 1, 0));
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
};

int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string k;
        cin >> k;
        Solution sol;
        cout << sol.longestPalinSubseq(k) << "\n";
    }
    return 0;
}