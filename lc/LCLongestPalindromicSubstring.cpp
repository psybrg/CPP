#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        int start = 0, i = 0, mx = 1;
        while(i < s.size()){
            int hi = i, lo = i;
            while (hi < s.size() - 1 && s[hi] == s[hi + 1]) hi++;
            i = hi + 1;
            while(hi < s.size() - 1 && lo > 0 && s[lo - 1] == s[hi + 1]) {
                lo--;
                hi++;
            }
            if(mx < (hi - lo + 1)){
                start = lo;
                mx = hi - lo + 1;
            }
            cout << lo << "\t" << hi << "\n";
        }
        return s.substr(start, mx);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a;
    cin >> a;
    Solution solution;
    cout << solution.longestPalindrome(a) << "\n";
    return 0;
}
