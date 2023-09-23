#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int findPeakElement(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid0 = (lo + hi) / 2;
            int mid1 = mid0 + 1;
            if (nums[mid0] < nums[mid1]) {
                lo = mid1;
            } else if (nums[mid0] > nums[mid1]) {
                hi = mid0;
            } else {
                return mid0;
            }
            cout << lo << "\t" << mid0 << "\t" << mid1 << "\t" << hi << "\n";
        }
        return lo;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.findPeakElement(nums) << "\n";
    return 0;
}