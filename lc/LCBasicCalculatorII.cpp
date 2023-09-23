#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void printVectors(vector<ll> a, vector<char> b) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << "\t";
        }
        cout << "\n";
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << "\t";
        }
        cout << "\n";
    }
    int calculate(string s, int k) {
        vector<ll> nums;
        vector<char> symbols;
        string t = "";
        int ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                t += s[i];
            } else if (s[i] == '-') {
                nums.push_back(stoi(t));
                nums.push_back(-1);
                symbols.push_back('+');
                symbols.push_back('*');
                t = "";
            } else if (s[i] == '+' || s[i] == '*' || s[i] == '/') {
                nums.push_back(stoi(t));
                symbols.push_back(s[i]);
                t = "";
            }
        }
        nums.push_back(stoi(t));
        // printVectors(nums, symbols);
        for (int i = 0; i < symbols.size(); i++) {
            if (symbols[i] == '/') {
                nums[i] /= nums[i + 1];
                nums.erase(nums.begin() + i + 1);
                symbols.erase(symbols.begin() + i);
                i--;
            } else if (symbols[i] == '*') {
                nums[i] *= nums[i + 1];
                nums.erase(nums.begin() + i + 1);
                symbols.erase(symbols.begin() + i);
                i--;
            }
        }
        // printVectors(nums, symbols);
        for (int i = 0; i < symbols.size(); i++) {
            if (symbols[i] == '+') {
                nums[i] += nums[i + 1];
                nums.erase(nums.begin() + i + 1);
                symbols.erase(symbols.begin() + i);
                i--;
            } else if (symbols[i] == '-') {
                nums[i] -= nums[i + 1];
                nums.erase(nums.begin() + i + 1);
                symbols.erase(symbols.begin() + i);
                i--;
            }
        }
        // printVectors(nums, symbols);
        return nums[0];
    }
    void printStack(stack<int>s, stack<char>t){
        cout << "nums->\t";
        while (!s.empty()) {
            cout << s.top() << "\t";
            s.pop();
        }
        cout << "\nsyms->\t";
        while (!t.empty()) {
            cout << t.top() << "\t";
            t.pop();
        }
        cout << "\n\n";
    }
    int evaluate(int a, int b, char c) {
        if (c == '+') return a + b;
        if (c == '/') return a / b;
        return a * b;
    }
    bool isSymbol(char c) {
        return c == '+' || c == '-' || c == '/' || c == '*';
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> symbols;
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                t += s[i];
            } else if (isSymbol(s[i])) {
                if (s[i] == '-') {
                    nums.push(stoi(t));
                    if (symbols.size() > 0 && nums.size() > 1 &&
                        (symbols.top() == '*' || symbols.top() == '/')) {
                        int a = nums.top();
                        nums.pop();
                        int b = nums.top();
                        nums.pop();
                        nums.push(evaluate(b, a, symbols.top()));
                        symbols.pop();
                    }
                    nums.push(-1);
                    symbols.push('+');
                    symbols.push('*');
                    t = "";
                } else if (s[i] == '+' || s[i] == '*' || s[i] == '/') {
                    nums.push(stoi(t));
                    // printStack(nums, symbols);
                    if (symbols.size() > 0 && nums.size() > 1 &&
                        (symbols.top() == '*' || symbols.top() == '/')) {
                        int a = nums.top();
                        nums.pop();
                        int b = nums.top();
                        nums.pop();
                        nums.push(evaluate(b, a, symbols.top()));
                        symbols.pop();
                    }
                    symbols.push(s[i]);
                    t = "";
                }
                // printStack(nums, symbols);
            }
        }
        nums.push(stoi(t));
        printStack(nums, symbols);
        while (!symbols.empty() &&
               (symbols.top() == '*' || symbols.top() == '/')) {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(evaluate(b, a, symbols.top()));
            symbols.pop();
        }
        while(nums.size()>1){
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push(evaluate(b, a, '+'));
        }
        return nums.top();
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    Solution solution;
    cout << solution.calculate(s) << "\n";
    return 0;
}