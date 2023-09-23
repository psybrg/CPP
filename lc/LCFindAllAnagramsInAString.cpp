#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void print(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    bool equalHash(vector<int>&a, vector<int>&b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string txt, string ptn) {
        vector<int> txtHsh(26, 0);
        vector<int> ptnHsh(26, 0);
        vector<int> ans;
        if (ptn.size() > txt.size()) return ans;
        for (int i = 0; i < txt.size() && i < ptn.size(); i++) {
            txtHsh[txt[i] - 'a']++;
        }
        for (int i = 0; i < ptn.size(); i++) {
            ptnHsh[ptn[i] - 'a']++;
        }
        for (int i = ptn.size(); i < txt.size(); i++)
        {
            if(equalHash(txtHsh, ptnHsh)) {
                ans.push_back(i - ptn.size());
            }
            // print(txtHsh);
            // print(ptnHsh);
            // cout << "\n";
            txtHsh[txt[i - ptn.size()] - 'a']--;
            txtHsh[txt[i] - 'a']++;
        }
        if (equalHash(txtHsh, ptnHsh)) {
            ans.push_back(txt.size() - ptn.size());
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    Solution solution;
    vector<int> v = solution.findAnagrams(a, b);
    solution.print(v);
    return 0;
}