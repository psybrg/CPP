#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
    int maximumUniqueSubarray(vector<int> &nums){
        int max = 0, sum = 0, head = 0;
        map<int, int> elements;
        for (int i = 0; i < nums.size(); i++)
        {
            if (elements.find(nums[i]) == elements.end())
            {
                sum += nums[i];
                elements.insert(pair<int, int>(nums[i], i));
            }
            else
            {
                sum = 0;
                head = head > (elements[nums[i]] + 1) ? head : (elements[nums[i]] + 1);
                elements[nums[i]] = i;
                for (int j = head; j <= i; j++)
                {
                    sum += nums[j];
                }
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
