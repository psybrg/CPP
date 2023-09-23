#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    int factorial(int n){
        if(n < 2)
            return 1;
        return n * factorial(n - 1);
    }
    vector<vector<int> > rec(set<int> nums){
        vector<vector<int> > ans(factorial(nums.size()), vector<int>(nums.size()));
        int l = 0;
        for (int num : nums)
        {
            set<int> subNum(nums);
            subNum.erase(num);
            vector<vector<int> > subAns = rec(subNum);
            for (int j = 0; j < subAns.size(); j++,l++)
            {
                ans[l][0] = (num);
                for (int k = 0; k < subAns[j].size(); k++)
                {
                    ans[l][k+1] = (subAns[j][k]);
                }
            }
        }
        return ans;
    }
    vector<vector<int> > permute(vector<int> &nums)
    {
        return rec(set<int>(nums.begin(), nums.end()));
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<int> nums(r);
    for (int i = 0; i < r; i++) cin >> nums[i];
    Solution solution;
    vector<vector<int> > ans = solution.permute(nums);
    for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << "\t";
		}
		cout << "\n";
	}
	return 0;
}
