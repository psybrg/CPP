#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
    int kthLargestElement(vector<int> &nums, int k){
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
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
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution solution;
    cout << solution.kthLargestElement(nums, k) << "\n";
    return 0;
}