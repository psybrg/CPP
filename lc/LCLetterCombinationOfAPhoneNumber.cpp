#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    string dgt;
    vector<string> data;
    vector<string> letterCombinations(int i) {
        if (i < dgt.size()) {
            vector<string> ans;
            for (int j = 0; j < data[dgt[i] - '0'].size(); j++) {
                vector<string> temp = letterCombinations(i + 1);
                for (int k = 0; k < temp.size(); k++) {
                    ans.push_back(data[dgt[i] - '0'][j] + temp[k]);
                }
            }
            return ans;
        }
        return vector<string>(1, "");
    }
    vector<string> letterCombinations(string digits) {
        dgt = digits;
        data.push_back("");
        data.push_back("");
        data.push_back("abc");
        data.push_back("def");
        data.push_back("ghi");
        data.push_back("jkl");
        data.push_back("mno");
        data.push_back("pqrs");
        data.push_back("tuv");
        data.push_back("wxyz");
        if (digits.size() < 1) return vector<string>(0);
        return letterCombinations(0);
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solution solution;
    string s;
    cin >> s;
    vector<string> ans = solution.letterCombinations(s);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}