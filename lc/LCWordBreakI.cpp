#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool searchString(string s, vector<string>& wordDict) {
        int lo = 0, hi = wordDict.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (s > wordDict[mid]) {
                lo = mid + 1;
            } else if (s < wordDict[mid]) {
                hi = mid - 1;
            } else
                return true;
        }
        return wordDict[lo] == s;
    }
    string substring(string s, int lo, int hi) {
        string t = "";
        if (lo > hi) {
            int t = lo;
            lo = hi;
            hi = t;
        }
        lo = lo < 0 ? 0 : lo;
        hi = hi < s.size() ? hi : s.size() - 1;
        for (int i = lo; i <= hi; i++) {
            t += s[i];
        }
        return t;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j >= 0; j--) {
                string temp = substring(s, j, i);
                if (searchString(temp, wordDict) && (j < 1 || dp[j - 1])) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size() - 1];
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r;
    cin >> r;
    Solution solution;
    vector<string> words(r);
    for (int i = 0; i < r; i++) {
        cin >> words[i];
    }
    cout << "\nEnter test cases : \n";
    bool doMore = true;
    while (doMore) {
        string test;
        cin >> test;
        doMore = test != " ";
        cout << solution.wordBreak(test, words) << "\n";
    }
    return 0;
}
/*

f(n) =


*/