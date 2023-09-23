#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int CountPS(string s, int n) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int lo = i;
            int hi = i;
            while (lo >= 0 && hi < n && s[lo] == s[hi]) {
                ans++;
                lo--;
                hi++;
            }
            lo = i;
            hi = i + 1;
            while (lo >= 0 && hi < n && s[lo] == s[hi]) {
                ans++;
                lo--;
                hi++;
            }
        }
        return ans - n;
    }
};

int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        string s;
        cin >> n >> s;
        Solution sol;
        cout << sol.CountPS(s, n);
    }
    return 0;
}
