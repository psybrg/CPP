#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    bool containsHash(vector<int> &txtHash, vector<int> &ptnHash) {
        if (txtHash.size() != ptnHash.size())
            return false;
        for (int i = 0; i < txtHash.size(); i++) {
            if (txtHash[i] < ptnHash[i]) {
                return false;
            }
        }
        return true;
    }
    void print(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << "\t";
        }
        cout << "\n";
    }
    string minWindow(string txt, string ptn) {
		if(txt.size() < ptn.size())
            return "";
        vector<int> ptnHash(259, 0);
        vector<int> txtHash(259, 0);
        cout << sizeof(txt[0]) << "\n";
        for (int i = 0; i < ptn.size(); i++) {
            txtHash[txt[i]]++;
            ptnHash[ptn[i]]++;
        }
        int lo = 0;
        int hi = ptn.size() - 1;
        bool containsPtn = containsHash(txtHash, ptnHash);
        int l = 0, r = txt.size() - 1;
        bool answerFound = containsPtn;
        while (lo <= hi && hi < txt.size()) {
            cout << lo << "\t" << hi << "\t" << txt.substr(lo, hi - lo + 1) << "\n";
            if (containsPtn) {
                if (r - l > hi - lo) {
                    l = lo;
                    r = hi;
                }
                txtHash[txt[lo]]--;
                containsPtn = txtHash[txt[lo]] >= ptnHash[txt[lo]];
                lo++;
                answerFound = true;
            } else {
                hi++;
                if (hi >= txt.size()) {
                    break;
                }
                txtHash[txt[hi]]++;
                if (containsPtn) {
                    containsPtn = ptnHash[txt[hi]] > 0 && txtHash[txt[hi]] >= ptnHash[txt[hi]];
                } else {
                    containsPtn = containsHash(txtHash, ptnHash);
                }
            }
            cout << lo << "\t" << hi << "\n\n";
        }
        if (!answerFound) {
            return "";
        }
        return txt.substr(l, r - l + 1);
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    Solution solution;
    cout << solution.minWindow(a, b) << "\n";
    return 0;
}
