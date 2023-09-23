#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(const vector<int> &a, const vector<int> &b) {
	return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
}

class Solution {
public:
	void print(vector<int> &rems) {
		for (int i = 0; i < rems.size(); i++) {
			cout << rems[i] << "\t";
		}
		cout << "\n";
	}
	vector<int> findLeastGreater(vector<int>& arr, int n) {
		set<int> s;
		vector<int> ans(n);
		for (int i = n - 1; i >= 0; i--)
		{
			s.insert(arr[i]);
			auto x = s.upper_bound(arr[i]);
			ans[i] = x == s.end() ? -1 : *x;
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
		vector<int> query(n);
		for (int i = 0; i < n; i++) {
			cin >> query[i];
		}

		Solution sol;
		vector<int> ans = sol.findLeastGreater(query, n);
		sol.print(ans);
	}
	return 0;
}