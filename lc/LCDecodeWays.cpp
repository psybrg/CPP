#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    map<string, string> cache = {{"1", "A"},  {"2", "B"},  {"3", "C"},  {"4", "D"},  {"5", "E"},{"6", "F"},  {"7", "G"},  {"8", "H"},  {"9", "I"},  {"10", "J"}, {"11", "K"}, {"12", "L"}, {"13", "M"}, {"14", "N"}, {"15", "O"}, {"16", "P"}, {"17", "Q"}, {"18", "R"}, {"19", "S"}, {"20", "T"}, {"21", "U"}, {"22", "V"}, {"23", "W"}, {"24", "X"}, {"25", "Y"}, {"26", "Z"}};
    int numDecodings(string s) {
        vector<int> dp(s.size() + 2, 1);
        if(s[0] == '0') {
            dp[0] = dp[1] = dp[2] = 0;
        }
        for (int i = 1; i < s.size(); i++) {
            dp[i + 1] = dp[i];
            string tmp = "11";
            tmp[0] = s[i - 1];
            tmp[1] = s[i];
            if(tmp[1] == '0' && tmp[0] != '1' && tmp[0] != '2') {
                return 0;
            }
            if(tmp[1] == '0') {
                dp[i + 1] = dp[i - 1];
                continue;
            }
            if (cache.find(tmp) != cache.end()) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[s.size()];
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    Solution solution;
    cout << solution.numDecodings(s) << "\n";
    return 0;
}