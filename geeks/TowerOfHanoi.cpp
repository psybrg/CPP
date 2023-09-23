#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    long long x = 0;
    long long toh(int n, int from, int to, int aux) {
        if (n < 2) {
            x++;
            printf("move disk %d from rod %d to rod %d\n", n, from, to);
            return n;
        }
        toh(n - 1, from, aux, to);
        x++;
        printf("move disk %d from rod %d to rod %d\n", n, from, to);
        toh(n - 1, aux, to, from);
        return x;
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
        Solution sol;
        cout << sol.toh(n, 1, 3, 2);
    }
    return 0;
}
