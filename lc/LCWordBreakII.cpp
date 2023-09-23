#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    vector<string> wordBreak(string &s, set<string> &dict, int idx) {
        vector<string> ans;
        if (idx < s.size()) {
            string t = "";
            for (int i = idx; i < s.size(); i++) {
                t += s[i];
                if (dict.find(t) != dict.end()) {
                    if (i + 1 < s.size()) {
                        vector<string> res = wordBreak(s, dict, i + 1);
                        if (res.size() > 0) {
                            for (int j = 0; j < res.size(); j++) {
                                ans.push_back(t + " " + res[j]);
                            }
                        }
                    } else {
                        ans.push_back(t);
                    }
                }
            }
        }
        return ans;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        return wordBreak(s, dict, 0);
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> input(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    Solution solution;
    vector<string> ans = solution.wordBreak(s, input);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}