#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<int> dp;
    int trailingZeroes(int n) {
        int f = 5, z = 0;
        while(f <= n){
            z += n / f;
            f *= 5;
        }
        return z;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Solution solution;
    cout << solution.trailingZeroes(n) << "\n";
    for (int i = 0; i < solution.dp.size(); i++) {
        cout << solution.dp[i] << " ";
    }
    cout << "\n";
    return 0;
}
