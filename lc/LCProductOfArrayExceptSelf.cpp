#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums){
        vector<int> ans(nums.size(),1);
        for (int i = 1; i < nums.size(); i++){
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (int i = nums.size()-2, num = 1; i >= 0; i--){
            ans[i] = ans[i] * num * nums[i + 1];
            num *= nums[i + 1];
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
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution solution;
    vector<int> ans = solution.productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << "\t";
    }
    cout << "\n";
    return 0;
}
