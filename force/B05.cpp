#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll diff(ll a,ll b)
{
    if(b>a)
        return (b-a);
    return 0;
}
int main(int argc, char const *argv[])
{
    vector<ll>v;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v.push_back(x);
    }
    ll s=0;
    for(ll i=1;i<v.size();i++)
    {
        s+=diff(v[i],v[i-1]);
    }
    cout<<s<<endl;
    return 0;
}
