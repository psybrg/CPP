#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Object{
    ll now;
    ll diff;
    ll index;
};
bool comparator(Object a, Object b){
    ll x =  a.diff - b.diff;
    return x<0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    vector<Object>Objects(n);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        scanf("%lld",&x);
        Objects[i].now = x;
    }
    for (ll i = 0; i < n; i++)
    {
        ll x;
        scanf("%lld",&x);
        Objects[i].diff = Objects[i].now - x;
    }
    sort(Objects.begin(),Objects.end(),comparator);
    ll min = 0;
    for (ll i = 0; i < n; i++)
    {
        if(i<k || Objects[i].diff<0)
            min += Objects[i].now;
        else
            min += Objects[i].now - Objects[i].diff;
    }
    printf("%lld\n", min);
    return 0;
}
