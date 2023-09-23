#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void print(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << "\t";
        }
        cout << "\n";
    }
    string intToString(int n) {
        if (n == 0) return "0";
        string s = "";
        bool sign = n >= 0 ? false : true;
        n = n >= 0 ? n : -n;
        while (n > 0) {
            string t = "0";
            t[0] += n % 10;
            s = t + s;
            n /= 10;
        }
        return sign ? "-" + s : s;
    }
    bool isZeroString(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') return false;
        }
        return true;
    }
    string multiply(string num1, string num2) {
        vector<vector<int> > arr(num1.size(), vector<int>(num2.size(), 0));
        string s = "";
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++) {
                arr[i][j] = (num1[i] - '0') * (num2[j] - '0');
                if (i > 0 && j + 1 < arr[0].size()) {
                    arr[i][j] += arr[i - 1][j + 1];
                    arr[i - 1][j + 1] %= 10;
                }
            }
        }
        int r = arr.size() - 1, c = arr[0].size() - 1;
        while (r > 0 || c > 0) {
            s = (char)((arr[r][c] % 10) + '0') + s;
            if (c > 0) {
                arr[r][c - 1] += arr[r][c] / 10;
                c--;
            } else {
                arr[r - 1][c] += arr[r][c] / 10;
                r--;
            }
        }
        s = intToString(arr[r][c]) + s;
        for (int i = 0; i < arr.size(); i++) {
            print(arr[i]);
        }
        return isZeroString(s) ? "0" : s;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    Solution solution;
    cout << solution.multiply(a, b) << "\n";
    return 0;
}
