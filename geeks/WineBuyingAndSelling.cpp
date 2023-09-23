#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
	long long int wineSelling(vector<int> &Arr, int N) {
		ll cost = 0;
		for (int i = 1; i < Arr.size(); i++) {
			Arr[i] += Arr[i - 1];
			cost += abs(Arr[i - 1]);
		}
		return cost;
	}
	void print(vector<int> &rems) {
		for (int i = 0; i < rems.size(); i++) {
			cout << rems[i] << "\t";
		}
		cout << "\n";
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
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution sol;
		cout << sol.wineSelling(arr, n);
	}
	return 0;
}
