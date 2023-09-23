#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int divide(int dividend, int divisor) {
        int quotient = 0;
        int i = 0;
        bool sign = false;
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        if(dividend == INT_MIN) {
            if(divisor&1 == 1) {
                dividend++;
            }
            else {
                dividend = dividend >> 1;
                divisor = divisor >> 1;
            }
        }
        if(divisor == INT_MIN) {
            return 0;
        }
        if (divisor < 0) {
            sign = !sign;
            divisor = -divisor;
        }
        if (dividend < 0) {
            sign = !sign;
            dividend = -dividend;
        }
        while (dividend >= divisor) {
            int num = divisor;
            int div = 1;
            while ((num < (INT_MAX >> 1)) && (num << 1) < dividend) {
                num = num << 1;
                div = div << 1;
            }
            dividend -= num;
            quotient += div;
        }
        return sign ? -quotient : quotient;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s, t;
    cin >> s >>t;
    Solution solution;
    cout << solution.divide(s, t) << "\n";
    return 0;
}