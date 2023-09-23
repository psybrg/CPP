#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int happify(int n) {
        int sum = 0;
        n = n > 0 ? n : -n;
        // if (n < 10) return n;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        while (s.find(n) == s.end()) {
            s.insert(n);
            n = happify(n);
            cout << n << "\n";
        }
        return n == 1;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Solution solution;
    cout << solution.isHappy(n) << "\n";
    return 0;
}