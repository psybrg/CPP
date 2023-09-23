#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    string intToString(int n) {
        if (n == 0)
            return "0";
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
    int compress(string chars) {
        if (chars.size() < 2) {
            return chars.size();
        }
        string s = "";
        int x = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == chars[i - 1]) {
                x++;
            } else {
                if (x > 1) {
                    s += chars[i - 1] + intToString(x);
                } else {
                    s += chars[i - 1];
                }
                x = 1;
            }
        }
        if (x > 1) {
            s += chars[chars.size() - 1] + intToString(x);
        } else {
            s += chars[chars.size() - 1];
        }
        cout << s << "\n";
        chars.resize(s.size());
        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string n;
    cin >> n;
    Solution solution;
    cout << solution.compress(n) << "\n";
    return 0;
}