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
    int longestCommonSubsequence(string text1, string text2) {
        if(text2.size() > text1.size()){
            string t = text1;
            text1 = text2;
            text2 = t;
        }
        // vector<int> prev(text2.size() + 1, 0);
        // vector<int> curr;
        // for (int i = 0; i < text1.size(); i++) {
        //     curr = vector<int>(text2.size() + 1, 0);
        //     for (int j = 0; j < text2.size(); j++) {
        //         curr[j + 1] = text1[i] == text2[j] ? 1 + prev[j]
        //                                            : max(curr[j], prev[j + 1]);
        //         print(curr);
        //     }
        //     prev = curr;
        // }
        // print(prev);
        // print(curr);
        // return curr[curr.size() - 1];

        vector<vector<int> > dp(2, vector<int>(text2.size() + 1, 0));
        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                dp[i % 2][j + 1] = text1[i] == text2[j] ? 1 + dp[(i + 1) % 2][j] : max(dp[i % 2][j], dp[(i + 1) % 2][j + 1]);
            }
        }
        print(dp[0]);
        print(dp[1]);
        return max(dp[0][dp[0].size() - 1], dp[1][dp[1].size() - 1]);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    Solution solution;
    cout << solution.longestCommonSubsequence(a, b) << "\n";
    return 0;
}