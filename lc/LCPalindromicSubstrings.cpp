#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int lo = i;
            int hi = i;
            while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
                ans++;
                lo--;
                hi++;
            }
            lo = i;
            hi = i + 1;
            while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
                ans++;
                lo--;
                hi++;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a;
    cin >> a;
    Solution solution;
    cout << solution.countSubstrings(a) << "\n";
    return 0;
}
