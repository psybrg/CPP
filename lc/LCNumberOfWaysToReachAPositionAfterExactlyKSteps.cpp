#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    ll mag(ll a) { return a > 0 ? a : -a; }
    ll modInverse(ll n, ll mod){
        ll M = mod;
        ll x = 1, y = 0;
        if (M == 1) return 0;
        while(n > 1) {
            ll q = n / mod;
            ll t = mod;
            mod = n % mod;
            n = t;
            t = y;
            y = x - q * y;
            x = t;
        }
        return (x + M) % M;
    }
    ll product(ll a, ll b, ll mod) { return ((a % mod) * (b % mod)) % mod; }
    ll nCrMod(ll n, ll r, ll mod){
        if (r < 0) return 0;
        if (r < 1) return 1;
        if (r < 2) return n;
        ll f = 1;
        if (r > n / 2) r = n - r;
        for (ll i = 0; i < r; i++){
            f = product(product(f , n - i, mod) , modInverse(i + 1, mod), mod);
        }
        return f;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        ll d = mag(endPos - startPos);
        if ((d + k) % 2 == 1) return 0;
        return nCrMod(k, (k - d) / 2, 1000000007);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int l, r, k;
    cin >> l >> r >> k;
    Solution solution;
    cout << solution.numberOfWays(l, r, k) << "\n";
    return 0;
}
