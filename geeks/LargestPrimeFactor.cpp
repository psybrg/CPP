#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long int largestPrimeFactor(int N) {
        int largestPrime = -1;
        int i = 2;
        while (i * i <= N) {
            while (N % i == 0) {
                largestPrime = i;
                N /= i;
            }
			i++;
			cout << N << "\t" << i << "\n";
        }
		return N > 1 ? N : largestPrime;
    }
};

// HARD

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
        cout << sol.largestPrimeFactor(n) << "\n";
    }
    return 0;
}
