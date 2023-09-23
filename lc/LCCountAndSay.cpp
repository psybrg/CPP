#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<string> dp;
    // itoa
    string intToString(int n) {
        if (n == 0) return "0";
        string s = "";
        bool sign = n > 0 ? false : true;
        n = n > 0 ? n : -n;
        while (n > 0) {
            string t = "0";
            t[0] += n % 10;
            s = t + s;
            n /= 10;
        }
        return sign ? "-" + s : s;
    }
    string countAndSay(string s) {
        char c = s[0];
        int j = 1;
        string t = "";
        for (int i = 1; i < s.size(); i++) {
            if(s[i]==s[i-1]){
                j++;
            } else {
                t += intToString(j) + s[i - 1];
                j = 1;
            }
        }
        t += intToString(j) + s[s.size() - 1];
        return t;
    }
    string countAndSay(int n) {
        if (dp.size() < 1) {
            dp.push_back("1");
            dp.push_back("1");
        }
        if (n < dp.size()) return dp[n];
        for (int i = dp.size(); i <= n; i++) {
            dp.push_back(countAndSay(dp[i - 1]));
        }
        return dp[n];
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    cin >> a;
    Solution solution;
    cout << solution.countAndSay(a) << "\n";
    for (int i = 0; i < solution.dp.size(); i++) {
        cout << solution.dp[i] << "\n";
    }
    return 0;
}
