#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
	bool makeChanges(int N, int K, int target, vector<int> &coins) {
		if (K == 0)
			return 0;
		vector<vector<int>> dp(target + 1, vector<int>(K + 1, 0));
		dp[0][0] = 1;
		cout << "SDVSD\n";
		for (int t = 0; t <= target; t++) {
			for (int k = 1; k <= K; k++) {
				for (int i = 0; i < N; i++) {
					cout << t << "\t" << k << "\t" << coins[i] << "\n";
					if (t >= coins[i]) {
						if (k == 1) {
							dp[coins[i]][k] = 1;
						} else {
							dp[t][k] |= dp[t - coins[i]][k - 1];
						}
					}
				}
			}
		}
		return dp[target][K];
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
		ll n, k, target;
		cin >> n >> k >> target;
		vector<int> coins(n);
		for (int i = 0; i < n; i++) {
			cin >> coins[i];
		}

		Solution sol;
		cout << sol.makeChanges(n, k, target, coins);
	}
	return 0;
}
