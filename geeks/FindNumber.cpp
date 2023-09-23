#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
	ll findNumber(ll N) {
		ll x = 1;
		while (x * 5 < N) {
			x *= 5;
		}
		ll ans = 0;
		vector<int> rems;
		while (x > 0) {
			rems.push_back(N / x);
			N = N % x;
			x /= 5;
		}
		// print(rems);
		for (int i = rems.size() - 1; i > 0; i--) {
			if (rems[i] <= 0) {
				rems[i] += 5;
				rems[i - 1]--;
			}
		}
		// print(rems);
		int idx = 0;
		while(idx < rems.size() && rems[idx] < 1) {
			idx++;
		}
		while (idx < rems.size()) {
			if (rems[idx] >= 0) {
				// cout << rems[idx] << " ";
				rems[idx] = 2 * rems[idx] - 1;
				ans = 10 * ans + rems[idx];
				idx++;
			}
		}
		// print(rems);
		return ans;
	}
	void print(vector<int>&rems) {
		for (int i = 0; i < rems.size(); i++) {
			cout << rems[i] << "\t";
		}
		cout << "\n";
	}
};

int main(int argc, char const *argv[]) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		Solution sol;
		cout << sol.findNumber(n);
	}
	return 0;
}
