#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    vector<ll>v;
    ll n,b;
    cin>>n>>b;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin>>t;
        v.push_back(t);
    }
    if(n==0)
    {
        cout<<(b)<<endl;
        return 0;
    }
    ll min=v[0],ans=b;
    for(ll i = 1; i < n; i++)
    {
        ll k=b/min;
        ll c=b-k*min+k*v[i];
        if(ans<c)
            ans=c;
        if(min>v[i])
            min=v[i];
    }
    cout<<ans<<endl;
    return 0;
}
