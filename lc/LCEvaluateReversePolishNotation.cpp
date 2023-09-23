#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool isSymbol(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int calculate(int p, int q, char c) {
        if (c == '+') return p + q;
        if (c == '-') return q - p;
        if (c == '*') return p * q;
        return q / p;
    }
    bool isNumber(string s) { return !isSymbol(s); }
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() < 2) return stoi(tokens[0]);
        int x = 0;
        stack<int> intQ;
        stack<char> charQ;
        while (x < tokens.size() && isNumber(tokens[x])) {
            intQ.push(stoi(tokens[x++]));
        }
        charQ.push(tokens[x++][0]);
        while (!intQ.empty() && x < tokens.size()) {
            int p = intQ.top();
            intQ.pop();
            int q = intQ.top();
            intQ.pop();
            char c = charQ.top();
            charQ.pop();
            intQ.push(calculate(p, q, c));
            cout << p << "\t" << q << "\t" << c << "\n";
            while (x < tokens.size() && isNumber(tokens[x])) {
                intQ.push(stoi(tokens[x++]));
            }
            charQ.push(tokens[x++][0]);
        }
        int p = intQ.top();
        intQ.pop();
        int q = intQ.top();
        intQ.pop();
        char c = charQ.top();
        charQ.pop();
        return calculate(p, q, c);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> tokens(n);
    for (int i = 0; i < n; i++) cin >> tokens[i];
    Solution solution;
    cout << solution.evalRPN(tokens) << "\n";
    return 0;
}
/*
f(i)=max(f(i-1), a[i]+f(i-2))
*/