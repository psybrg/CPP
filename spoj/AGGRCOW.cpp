#include <bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<ll> v) {
    for (ll i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}
ll placeCows(vector<ll> barns, ll gap) {
    ll prvCow = 0, cowsPlaced = 1;
    for (ll i = 1; i < barns.size(); i++) {
        if (barns[i] - barns[prvCow] >= gap) {
            prvCow = i;
            cowsPlaced++;
        }
    }
    return cowsPlaced;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        ll n, cows;
        cin >> n >> cows;
        vector<ll> barns(n);
        for (ll i = 0; i < n; i++) cin >> barns[i];
        sort(barns.begin(), barns.end());
        ll ans = 1, lo = 1, hi = barns[barns.size() - 1] - barns[0];
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (placeCows(barns, mid) >= cows) {
                lo = mid + 1;
                ans = mid;
            } else
                hi = mid - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}