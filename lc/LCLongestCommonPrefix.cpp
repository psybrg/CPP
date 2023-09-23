#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
	string longestCommonPrefix(vector<string>& strs) {
		int x = strs[0].size();
		for (int i = 1; i < strs.size(); i++) {
			x = min(x, ((int)strs[i].size()));
			for (int j = 0; j <= x; j++) {
				if (strs[0][j] != strs[i][j]) {
					x = min(x, j);
					break;
				}
			}
		}
		return strs[0].substr(0, x);
	}
};
int main(int argc, char const* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<string> strs(n);
	for (int i = 0; i < n; i++) cin >> strs[i];
	Solution solution;
	cout << solution.longestCommonPrefix(strs) << "\n";
	return 0;
}
/*
f(i)=max(f(i-1), a[i]+f(i-2))
*/