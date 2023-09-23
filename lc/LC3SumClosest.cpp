#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int mag(int a) {
        return a > 0 ? a : -a;
    }
    int rangedClosestBinarySearch(vector<int> &v, int lo, int hi, int k) {
        lo = lo >= 0 && lo < v.size() ? lo : 0, hi = hi >= 0 && hi < v.size() ? hi : v.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] > k) {
                hi = mid - 1;
            } else if (v[mid] < k) {
                lo = mid + 1;
            } else {
                return v[mid];
            }
        }
        int t = lo;
        if (v[lo] > k) {
            while (t && v[t] == v[t - 1])
                t--;
        } else {
            while (t < v.size() - 1 && v[t] == v[t + 1])
                t++;
        }
        if (mag(v[lo] - k) > mag(v[t] - k)) {
            return v[t];
        }
        return v[lo];
    }
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int lo = 1; lo < nums.size() - 2; lo++) {
            int mid = lo + 1, hi = nums.size() - 1;
            while (mid < hi) {
                int sum = nums[lo] + nums[mid] + nums[hi];
                if (mag(sum - target) < mag(closestSum - target)) {
                    closestSum = sum;
                }
                if (sum > target)
                    hi--;
                else if (sum < target)
                    mid++;
                else
                    return sum;
            }
        }
        return closestSum;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution solution;
    cout << solution.threeSumClosest(nums, k) << "\n";
    return 0;
}