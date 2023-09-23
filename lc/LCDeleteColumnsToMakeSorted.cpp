#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int minDeletionSize(vector<string> &strs) {
        int ans = 0;
        for (int j = 0; j < strs[0].size(); j++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] < strs[i - 1][j]) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> tokens(n);
    for (int i = 0; i < n; i++)
        cin >> tokens[i];
    Solution solution;
    cout << solution.minDeletionSize(tokens) << "\n";
    return 0;
}