#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    double expo(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double y = expo(x, n / 2);
        if (n % 2 == 0) {
            return y * y;
        }
        return x * y * y;
    }
    double myPow(double x, int n) {
        if (n >= 0) {
            return expo(x, n);
        }
        return 1 / expo(x, n);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    double a;
    int b;
    cin >> a >> b;
    Solution solution;
    cout << solution.myPow(a, b) << "\n";
    return 0;
}