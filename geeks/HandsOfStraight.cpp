#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
	bool isStraightHand(int N, int groupSize, vector<int> &hand) {
		if (hand.size() % groupSize != 0) {
			return 0;
		}
		map<int, int> freq;
		set<int> nums;
		for (int i = 0; i < hand.size(); i++) {
			freq[hand[i]]++;
			nums.insert(hand[i]);
		}
		for (auto i = nums.begin(); i != nums.end(); i++) {
			if (freq[*i] > 0) {
				int num = freq[*i];
				for (int j = 0; j < groupSize; j++) {
					cout << *i + j << '\t' << freq[*i + j] << "\t" << j << '\n';
					if (freq[*i + j] > 0) {
						freq[*i + j] -= num;
					} else {
						return 0;
					}
					cout << *i + j << '\t' << freq[*i + j] << "\t" << j << "\n\n";
				}
			}
		}
		return 1;
	}
	void print(vector<int> &rems) {
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
		ll n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		Solution sol;
		cout << sol.isStraightHand(n, k, arr);
	}
	return 0;
}
