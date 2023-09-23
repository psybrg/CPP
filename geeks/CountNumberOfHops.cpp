#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countWays(int n) {
        long long mod = 1000000007;
        if (n < 2) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        if (n == 3) {
            return 4;
        }
        long long a = 1, b = 2, c = 4, ans = 0;
        for (int i = 3; i < n; i++) {
            ans = (a % mod + b % mod + c % mod) % mod;
            a = b;
            b = c;
            c = ans;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        Solution sol;
        cout << sol.countWays(n);
    }
    return 0;
}
