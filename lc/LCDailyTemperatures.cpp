#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> vs(temperatures.size(), 0);
        stack<pair<int,int> > stk;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty()) {
                pair<int, int> p = stk.top();
                if(p.second < temperatures[i]){
                    stk.pop();
                    vs[p.first] = i - p.first;
                }
                else break;
            }
            stk.push(pair<int,int>(i, temperatures[i]));
        }
        return vs;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r;
    cin >> r;
    vector<int> nums(r);
    for (int i = 0; i < r; i++) cin >> nums[i];
    Solution solution;
    vector<int> ans = solution.dailyTemperatures(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << "\n";
    return 0;
}
