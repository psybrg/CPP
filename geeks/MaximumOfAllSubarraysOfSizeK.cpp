#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(const vector<int> &a, const vector<int> &b) {
    return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
}

class Solution {
    public:
    void print(vector<int> &rems) {
        for (auto i = rems.begin(); i != rems.end(); i++) {
            cout << *i << " ";
        }
        cout << "\n";
    }
    void print(multiset<int> &rems) {
        for (auto i = rems.begin(); i != rems.end(); i++) {
            cout << *i << " ";
        }
        cout << "\n";
    }
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                st.erase(st.find(arr[i - k]));
            }
            st.insert(arr[i]);
            if (i >= k - 1) {
                ans.push_back(*st.rbegin());
            }
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
        query = sol.max_of_subarrays(query, n, k);
		cout<<"\n";
        sol.print(query);
    }
    return 0;
}