#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll>smush(ll a,vector<ll> v)
{
    for (size_t i = 0; i < v.size(); i++) {
        ll x=v[i];
        ll z=a;
        while(x>0){
            z=z*10;
            x=x/10;
        }
        v[i]+=z;
    }
    return v;
}
vector<ll>rec(ll a,ll b)
{
    if(a<=0&&b>0)
    {
        ll x=0;
        while(b--)
        {
            x=x*10+7;
        }
        vector<ll>v;
        v.push_back(x);
        return v;
    }
    if(b<=0&&a>0)
    {
        ll x=0;
        while(a--)
        {
            x=x*10+4;
        }
        vector<ll>v;
        v.push_back(x);
        return v;
    }
    vector<ll>v1=smush(4,rec(a-1,b));
    vector<ll>v2=smush(7,rec(a,b-1));
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}
int main(int argc, char const *argv[])
{
    vector<ll>v;
    for (size_t i = 1; i < 6; i++) {
        vector<ll>v1=rec(i,i);
        v.insert(v.end(),v1.begin(),v1.end());
    }
    ll n;
    cin>>n;
    ll lo=0,hi=v.size()-1;
    while(lo<hi){
        if(hi-lo==1)
            break;
        ll mid=lo+(hi-lo)/2;
        if(v[mid]>n)
            hi=mid;
        else
            lo=mid;
    }
    // cout<<lo<<"->"<<v[lo]<<" : "<<hi<<"->"<<v[hi]<<endl;
    if(v[lo]>=n)
        cout<<v[lo];
    else
        cout<<v[hi];
    cout<<endl;
    return 0;
}
