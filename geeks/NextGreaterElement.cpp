#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void print(vector<ll> &rems) {
        for (int i = 0; i < rems.size(); i++) {
            cout << rems[i] << "\t";
        }
        cout << "\n";
    }
    vector<long long> nextLargerElement(vector<long long> &arr, int n) {
        vector<long long> ans(n, -1);
        stack<long long> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= arr[i]) {
                stk.pop();
            }
            if (!stk.empty() && stk.top() > arr[i]) {
                ans[i] = stk.top();
            }
            stk.push(arr[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> query(n);
        for (int i = 0; i < n; i++) {
            cin >> query[i];
        }

        Solution sol;
        vector<ll> ans = sol.nextLargerElement(query, n);
        sol.print(ans);
    }
    return 0;
}