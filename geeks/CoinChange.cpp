#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(const vector<int> &a, const vector<int> &b) {
    return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
}

class Solution {
    public:
    void print(vector<int> &rems) {
        for (auto i = rems.begin(); i != rems.end(); i++) {
            cout << *i << " ";
        }
        cout << "\n";
    }
    long long count(vector<int> &coins, int n, int sum) {
        vector<long long int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= sum; i++) {
                if (i >= coins[j]) {
                    dp[i] += dp[i - coins[j]];
                }
            }
        }
        // print(dp);
        return dp[sum];
    }
};

// HARD

int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<int> query(n);
        for (int i = 0; i < n; i++) {
            cin >> query[i];
        }

        Solution sol;
        cout << sol.count(query, n, k) << "\n";
    }
    return 0;
}