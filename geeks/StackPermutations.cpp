#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
	int isStackPermutation(int N, vector<int> &A, vector<int> &B) {
		stack<int> stk;
		int j = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] == B[j]) {
				j++;
				while (!stk.empty() && stk.top() == B[j]) {
					stk.pop();
					j++;
				}
			} else if (stk.empty()) {
				stk.push(A[i]);
			} else if (stk.top() == B[j]) {
				while (!stk.empty() && stk.top() == B[j]) {
					stk.pop();
					j++;
				}
			} else {
				stk.push(A[i]);
			}
		}
		while (!stk.empty() && j < N  && stk.top() == B[j]) {
			stk.pop();
			j++;
		}
		return stk.empty() ? 1 : 0;
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
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		Solution sol;
		cout << sol.isStackPermutation(n, a, b);
	}
	return 0;
}
