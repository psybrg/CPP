#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        int ans = 0;
        map<int, int> n0, n1;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (n0.find(nums1[i] + nums2[j]) == n0.end()) {
                    n0.insert(pair<int, int>(nums1[i] + nums2[j], 1));
                } else {
                    n0[nums1[i] + nums2[j]]++;
                }
                if (n1.find(nums3[i] + nums4[j]) == n1.end()) {
                    n1.insert(pair<int, int>(nums3[i] + nums4[j], 1));
                } else {
                    n1[nums3[i] + nums4[j]]++;
                }
            }
        }
        for (auto i = n0.begin(); i != n0.end(); i++) {
            if (n1.find(-i->first) != n1.end()) {
                ans += i->second * n1[-i->first];
            }
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> n0(n), n1(n), n2(n), n3(n);
    for (int i = 0; i < n; i++) {
        cin >> n0[i];
        cin >> n1[i];
        cin >> n2[i];
        cin >> n3[i];
    }
    Solution solution;
    cout << solution.fourSumCount(n0, n1, n2, n3) << "\n";
    return 0;
}

/*
f(n, 0) = f(n-1,0), f(n-1,1) - a[n]
f(n, 1) = f(n-1,1), f(n-1,0) + a[n]

/**/