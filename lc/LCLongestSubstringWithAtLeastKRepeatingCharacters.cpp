#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool isValidHash(vector<int>& freq, int k) {
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 0 && freq[i] < k) return false;
        }
        return true;
    }
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (k > n) return 0;
        if (k <= 1) return n;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i <= (n - k); i++) {
            // for (int j = 0; j < i; j++) {
            //     freq[s[n - 1 - j] - 'a']--;
            // }
            int lo = 0, hi = n - 1 - i;
            while (hi < n) {
                if (isValidHash(freq, k)) return hi - lo + 1;
                if ((hi + 1) < n) {
                    freq[s[lo++] - 'a']--;
                    freq[s[++hi] - 'a']++;
                }
                else break;
                cout << lo << "\t" << hi << "\n";
            }
            while (lo > 0) {
                freq[s[--lo] - 'a']++;
                freq[s[hi--] - 'a']--;
                cout << lo << "\t" << hi << "\n";
            }
            freq[s[hi] - 'a']--;
        }
        return 0;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    int k;
    cin >> k;
    cin >> s;
    Solution solution;
    cout << solution.longestSubstring(s, k) << "\n";
    return 0;
}

/*
DnC(lo, hi, str){
    hash(str, lo, hi);
    for(0<hash(a->z)<k){
        choose any index of char not to be included
        return max(DnC(lo, idx - 1, str), DnC(idx + 1, hi, str));
    }
    return hi - lo;
}
*/

/*
uniqueChars, moreThanKChars, 2 pointers lo and hi, allowedUniqueChars[1:26]
while(allowedUniqueChars[]){
    uniqueChars = 0;
    moreThanKChars = 0;
    lo = 0;
    hi = 0;
    hash(26,0);
    while(hi<str.size()){
        if(uniqueChars <= allowedUniqueChars){
            hi++;
            hash[char]++;
            hash[char]==1?unique++; //new char added, was not previously
            hash[char]==k?moreThanKChars++; // * hash[char==k] *
        }
        else{
            lo++;
            hash[char]==k?moreThanKChars--; //
            hash[char]--;
            hash[char]==0?unique--; //char deleted
        }
        if(allowedUniqueChars[]==unique &&
allowedUniqueChars[]==moreThanKChars){ ans = max(ans, hi-lo);
        }
    }
}
*/

/*
if(k>n)return 0;
if(k==1)return n;
Sliding window:
    slide window of sizes[n->k]
    when encounter valid hash return window size
*/