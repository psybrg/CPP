#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<int> dp;
    int reverse(int n) {
        int x = n;
        while (x % 10 == 0 && x != 0) {
            x /= 10;
        }
        bool sign = x >= 0 ? false : true;
        if (x == INT_MIN) return 0;
        x = x >= 0 ? x : -x;
        n = x;
        int reverse = 0;
        while (x > 0) {
            int remainder = x % 10;
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && remainder > 7))
                return 0;
            if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && remainder < -8))
                return 0;
            reverse = reverse * 10 + remainder;
            x /= 10;
        }
        x = reverse;
        int c = 0;
        while (x > 0) {
            c = c * 10 + x % 10;
            x /= 10;
        }
        if (n == c && !sign) return reverse;
        if (n == c && sign) return -reverse;
        return 0;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Solution solution;
    cout << solution.reverse(n) << "\n";
    for (int i = 0; i < solution.dp.size(); i++) {
        cout << solution.dp[i] << " ";
    }
    cout << "\n";
    return 0;
}
