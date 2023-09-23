#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<vector<string> > partition(string s) {
        int len = s.length();
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        vector<vector<string> > result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string> > &result, string &s, int start,
             vector<string> &currentList, vector<vector<bool> > &dp) {
        if (start >= s.length()) {
            result.push_back(currentList);
        }
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r;
    cin >> r;
    Solution solution;
    string s;
    cin >> s;
    vector<vector<string> > ans = solution.partition(s);
    for (int j = 0; j < ans.size(); j++) {
        for (int i = 0; i < ans[j].size(); i++) {
            cout << ans[j][i] << " ";
        }
        cout << "\n";
    }
    return 0;
}