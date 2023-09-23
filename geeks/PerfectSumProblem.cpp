#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int perfectSum0(vector<int> &arr, int n, int sum) {
        int mod = 1000000007;
        vector<vector<long long>> dp(n + 1, vector<long long>(sum + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j] % mod;
                if (j >= arr[i - 1]) {
                    dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - arr[i - 1]] % mod) % mod;
                }
            }
        }
        return dp[n][sum];
    }
    int perfectSum(vector<int> &arr, int n, int sum) {
        int mod = 1000000007;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= arr[i]; j--) {
                if (dp[j - arr[i]] > 0) {
                    dp[j] = (dp[j - arr[i]] % mod + dp[j] % mod) % mod;
                }
            }
        }
        return dp[sum];
    }
    void print(vector<int> &rems) {
        for (int i = 0; i < rems.size(); i++) {
            cout << rems[i] << "\t";
        }
        cout << "\n";
    }
};

// HARD

int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int sum, n;
        cin >> n >> sum;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution sol;
        cout << sol.perfectSum(arr, n, sum);
    }
    return 0;
}

/*
f[i, a, b] = f[i, a * v[i], b] || f[i + 1, a, b]
*/