#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> dict;
        for (int i = 0; i < nums.size(); i++)
        {
            if (dict.find(nums[i]) == dict.end())
            {
                dict[nums[i]] = 1;
            }
            else
            {
                dict[nums[i]]++;
            }
        }
        set<pair<int, int> > s;
        for (auto i = dict.begin(); i != dict.end(); i++)
        {
            s.insert(pair<int, int>(i->second, i->first));
        }
        vector<int> ans;
        auto p = s.rbegin();
        for (int i = 0; i < k && p != s.rend(); i++, p++)
        {
            ans.push_back(p->second);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    vector<int> ans = solution.topKFrequent(nums, k);
    for (int j = 0; j < ans.size(); j++)
    {
        cout << ans[j] << "\t";
    }
    cout << "\n";
	return 0;
}
