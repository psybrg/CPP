#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void print(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << "\t";
        }
        cout << "\n";
    }
    vector<int> partitionLabels(string s) {
        vector<vector<int> >v(26, vector<int>(2, -1));
        for (int i = 0; i < s.size(); i++) {
            if (v[s[i] - 'a'][0] < 0) {
                v[s[i] - 'a'][0] = i;
                v[s[i] - 'a'][1] = i;
            }
            else {
                v[s[i] - 'a'][1] = i;
            }
        }
        set<vector<int> > dmp;
        for (int i = 0; i < v.size(); i++){
            if(v[i][0] >= 0 && v[i][1] >= 0) {
                dmp.insert(v[i]);
            }
        }
        v = vector<vector<int> >(dmp.begin(), dmp.end());
        vector<int> dsu(v.size());
        for (int i = 0; i < dsu.size(); i++) {
            dsu[i] = i;
        }
        for (int i = 1; i < v.size(); i++) {
            if(v[i][0] <= v[i - 1][1]) {
                dsu[i] = dsu[i - 1];
                v[i - 1][0] = v[i][0] = min(v[i - 1][0], v[i][0]);
                v[i - 1][1] = v[i][1] = max(v[i - 1][1], v[i][1]);
            }
        }
        vector<int> ans;
        print(dsu);
        for (int i = 0; i < dsu.size(); i++) {
            print(v[i]);
        }
        for (int i = 0; i < dsu.size(); i++) {
            int mn = v[i][0];
            int mx = v[i][1];
            while (i < dsu.size() - 1 && dsu[i] == dsu[i + 1]) {
                mn = min(mn, v[i + 1][0]);
                mx = max(mx, v[i + 1][1]);
                i++;
            }
            ans.push_back(mx - mn + 1);
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a;
    cin >> a;
    Solution solution;
    vector<int> v = solution.partitionLabels(a);
    solution.print(v);
    return 0;
}