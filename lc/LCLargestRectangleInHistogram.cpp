#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> stk;
		
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    Solution solution;
    cout << solution.largestRectangleArea(coins) << "\n";
    return 0;
}