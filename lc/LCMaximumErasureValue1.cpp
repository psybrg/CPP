#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
    int maximumUniqueSubarray(vector<int> &nums){
        int max = 0, sum = 0, head = 0;
        vector<int> prefix(1, nums[0]);
        vector<int> elements(10001, -1);
        for (int i = 1; i < nums.size(); i++){
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
        for (int i = 0; i < nums.size(); i++){
            if (elements[nums[i]] == -1){
                sum += nums[i];
                elements[nums[i]] = i;
            }
            else{
                head = head > (elements[nums[i]] + 1) ? head : (elements[nums[i]] + 1);
                sum = prefix[i] - (head > 0 ? prefix[head - 1] : 0);
                elements[nums[i]] = i;
            }
            max = max > sum ? max : sum;
        }
        return max;
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
    cout << solution.maximumUniqueSubarray(nums) << "\n";
    return 0;
}
