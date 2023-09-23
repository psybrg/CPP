#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > ans;
        int num = 1 << nums.size();
        for (int i = 0; i < num; i++)
        {
            vector<int> v;
            int k = 1;
            for (int j = 0; j < nums.size(); j++, k *= 2)
            {
                if ((k & i) != 0)
                {
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    vector<vector<int> > ans = solution.subsets(nums);
    for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
        {
			cout << ans[i][j] << "\t";
		}
		cout << "\n";
	}
	return 0;
}
