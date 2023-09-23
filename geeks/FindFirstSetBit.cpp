#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long int getFirstSetBit(int n) {
        n = n & -n;
        int pos = 0;
        while(n != 0) {
            pos++;
            n = n >> 1;
        }
        return pos;
    }
};

// HARD

int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        Solution sol;
        cout << sol.getFirstSetBit(n) << "\n";
    }
    return 0;
}
