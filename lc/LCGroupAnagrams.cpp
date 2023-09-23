#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs){
        vector<vector<string> > ans;
        map<string, vector<string> > cache;
        for (int i = 0; i < strs.size(); i++){
            string t = strs[i];
            sort(t.begin(), t.end());
            if (cache.find(t) == cache.end())
            {
                cache.insert(pair<string, vector<string> >(t, vector<string>(1, strs[i])));
            }
            else{
                cache[t].push_back(strs[i]);
            }
        }
        for (auto it = cache.begin(); it != cache.end(); ++it)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r;
    cin >> r;
    Solution solution;
    vector<string > strs(r);
    for (int i = 0; i < r; i++){
            cin >> strs[i];
    }
    vector<vector<string> > ans = solution.groupAnagrams(strs);
    for (int j = 0; j < ans.size(); j++){
        for (int i = 0; i < ans[j].size(); i++){
            cout << ans[j][i] << " ";
        }
        cout << "\n";
    }
    return 0;
}