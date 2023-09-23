#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    string replicateString(string s, int n) {
        string t = "";
        for (int i = 0; i < n; i++){
            t += s;
        }
        return t;
    }
    string decodeString(string s) {
        stack<int> frq;
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                string num = "0";
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    num += s[i];
                    i++;
                }
                cout << num << "\t" << stoi(num) << "\n";
                frq.push(stoi(num));
            }
            if (i < s.size() && s[i] != ']') {
                stk.push(s[i]);
            }
            if (i < s.size() && s[i] == ']') {
                string t = "";
                while (!stk.empty() && stk.top() != '[') {
                    t = stk.top() + t;
                    stk.pop();
                }
                string r = replicateString(t, frq.top());
                frq.pop();
                stk.pop();
                for (int j = 0; j < r.size(); j++) {
                    stk.push(r[j]);
                }
            }
        }
        string ans = "";
        while (!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a;
    cin >> a;
    Solution solution;
    cout << solution.decodeString(a) << "\n";
    return 0;
}
