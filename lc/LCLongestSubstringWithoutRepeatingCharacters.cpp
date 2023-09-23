#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool isValidHash(vector<int>& freq, int k) {
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 1) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 1) return 0;
        int lo = 0, ans = 1;
        vector<int> hash(256, 0);
        hash[s[0]]++;
        vector<int> posn(256, -1);
        posn[s[0]] = 0;
        for (int hi = 1; hi < s.size(); hi++) {
            if (hash[s[hi]] == 0){
                hash[s[hi]]++;
            } 
            else {
                while(lo < (posn[s[hi]])){
                    hash[s[lo]]--;
                    posn[s[lo]] = -1;
                    lo++;
                }
                lo++;
            }
            cout << lo << "\t" << hi << "\n";
            ans = max(ans, hi - lo + 1);
            posn[s[hi]] = hi;
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << "\n";
    return 0;
}
