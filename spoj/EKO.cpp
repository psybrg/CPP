#include <bits/stdc++.h>
using namespace std;
#define ll long long
void print(vector<ll> v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
ll getAltSum(vector<ll> v, ll mid)
{
    ll sum = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (mid < v[i])
        {
            sum += v[i] - mid;
        }
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll lo = 1, hi = 2000000000, ans = 1;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (getAltSum(v, mid) >= k)
        {
            lo = mid + 1;
            ans = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}