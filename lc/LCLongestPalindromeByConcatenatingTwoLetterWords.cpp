#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void printSpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                cout << (char)((i / 26) + 'a') << (char)((i % 26) + 'a') << " : " << nums[i] << "\t";
            }
        }
        cout << "\n";
    }
    int longestPalindrome(vector<string>& words) {
        vector<int> frq(700, 0);
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            frq[(words[i][0] - 'a') * 26 + words[i][1] - 'a']++;
        }
        printSpecial(frq);
        for (int i = 0; i < frq.size(); i++) {
            char c0 = (i / 26) + 'a';
            char c1 = (i % 26) + 'a';
            if (c0 == c1) {
                if ((ans / 2) % 2 == 1 && frq[i] % 2 == 1) {
                    ans -= 2;
                }
                ans += 2 * frq[i];
            } else {
                int j = (c1 - 'a') * 26 + c0 - 'a';
                ans += min(frq[i], frq[j]) * 4;
                frq[i] = 0;
                frq[j] = 0;
            }
            // cout << (char)((i / 26) + 'a') << (char)((i % 26) + 'a') << " : " <<  ans << "\t";
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.longestPalindrome(nums) << "\n";
    return 0;
}