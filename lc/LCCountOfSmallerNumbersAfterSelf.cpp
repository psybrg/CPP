#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int F_SIZE = 20002;
    int OFFSET = 10001;
    vector<int> fenwick;
    void print(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= (i & -i)) {
            sum += fenwick[i];
        }
        return sum;
    }
    void update(int i) {
        for (; i < F_SIZE; i += (i & -i)) {
            fenwick[i]++;
        }
    }
    vector<int> countSmaller(vector<int> &nums, int range) {
        OFFSET = range + 1;
        F_SIZE = OFFSET * 2;
        fenwick = vector<int>(F_SIZE, 0);
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = query(OFFSET + nums[i] - 1);
            update(OFFSET + nums[i]);
            print(fenwick);
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
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution solution;
    vector<int> ans = solution.countSmaller(nums, k);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << "\n";
    return 0;
}
/*

Pre Requisite Fenwick Tree

Keep storing frequencies of encountered ranged offsets of elements using update().

Query for sum of frequecies of numbers just less than the queried element.

0 ---> (i - 1)  // these are the frequecies of elements

*/
