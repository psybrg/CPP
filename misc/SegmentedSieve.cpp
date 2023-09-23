#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
void print(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\t";
    cout << endl;
}
void updateSieve(ll limit, vector<ll> &primes)
{
    if (primes.size() < 1 || limit > primes[primes.size() - 1])
    {
        vector<bool> newPrimes(limit + 1, true);
        for (ll i = 2; i * i <= limit; i++)
            if (newPrimes[i])
                for (ll j = i * i; j <= limit; j += i)
                    newPrimes[j] = false;
        for (ll i = primes.size() > 0 ? (primes[primes.size() - 1] + 1) : 2; i < newPrimes.size(); i++)
            if (newPrimes[i])
                primes.push_back(i);
    }
}
void printSieve(ll lo, ll hi, vector<ll> &primes)
{
    vector<bool> newPrimes(hi - lo + 1, true);
    for (ll i = 0; i < primes.size(); i++)
    {
        ll x = lo / primes[i];
        if (x <= 1)
            x = 2 * primes[i];
        else if (lo % primes[i])
            x = x * primes[i] + primes[i];
        else
            x *= primes[i];
        for (ll j = x; j <= hi; j += primes[i])
            newPrimes[j - lo] = false;
    }
    for (ll i = lo; i <= hi; i++)
        if (newPrimes[i - lo] && i > 1)
            printf("%lld\n", i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    scanf("%lld", &t);
    vector<ll> primes;
    while (t--)
    {
        ll lo, hi;
        scanf("%lld", &lo);
        scanf("%lld", &hi);
        updateSieve(sqrt(hi) + 1, primes);
        printSieve(lo, hi, primes);
        // printf("\n");
    }
    return 0;
}