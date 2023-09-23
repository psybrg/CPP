#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(const vector<int> &a, const vector<int> &b) {
	return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
}

class Solution {
public:
	void print(multiset<int> &rems) {
		for (auto i = rems.begin(); i != rems.end(); i++) {
			cout << *i << " ";
		}
		cout << "\n";
	}
	int kthLargest(vector<int> &arr, int n, int k){
        multiset<int>s;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += arr[j];
                s.insert(sum);
                if(s.size() > k) {
                    s.erase(s.begin());
                }
				print(s);
			}
        }
        return *s.begin();
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
		cout << sol.kthLargest(query, n, k) << "\n";
	}
	return 0;
}