#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    vector<string> split(string s, char c) {
        vector<string> result;
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (c == s[i]) {
                result.push_back(tmp);
                tmp = "";
            } else {
                tmp += s[i];
            }
        }
        result.push_back(tmp);
        return result;
    }
    bool wordPattern(string pattern, string s) {
        map<char, string> hash0;
        map<string, char> hash1;
        vector<string> res = split(s, ' ');
        if (res.size() != pattern.size())
            return false;
        for (int i = 0; i < pattern.size() && i < res.size(); i++) {
            if ((hash0.find(pattern[i]) == hash0.end() && hash1.find(res[i]) == hash1.end()) || (hash0[pattern[i]] == res[i] && hash1[res[i]] == pattern[i])) {
                cout << pattern[i] << "\t" << res[i] << "\n";
                hash0[pattern[i]] = res[i];
                hash1[res[i]] = pattern[i];
            } else {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    getline(std::cin, a);
    getline(std::cin, b);
    Solution solution;
    cout << solution.wordPattern(a, b) << "\n";
    return 0;
}