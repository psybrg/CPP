#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        for (int i = 0; i < capacity.size(); i++) {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        int ans = 0;
        for (int i = 0; i < capacity.size(); i++) {
            if (capacity[i] <= additionalRocks) {
                additionalRocks -= capacity[i];
                ans++;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> nums0(n);
    vector<int> nums1(n);
    for (int i = 0; i < n; i++)
        cin >> nums0[i];
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    Solution solution;
    cout << solution.maximumBags(nums0, nums1, k) << "\n";
    return 0;
}
