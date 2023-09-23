#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    public:
    void print(vector<int> &rems) {
        for (auto i = rems.begin(); i != rems.end(); i++) {
            cout << *i << " ";
        }
        cout << "\n";
    }
    vector<int> nearlySorted(vector<int> arr, int n, int K) {
        vector<int> ans;
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(arr[i]);
            if (i >= K) {
                ans.push_back(*st.begin());
                st.erase(st.begin());
            }
        }
        for (auto i = st.begin(); i != st.end(); i++) {
            ans.push_back(*i);
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
        ll n, k;
        cin >> n >> k;
        vector<int> query(n);
        for (int i = 0; i < n; i++) {
            cin >> query[i];
        }

        Solution sol;
        sol.print(sol.nearlySorted(query, n, k));
    }
    return 0;
}