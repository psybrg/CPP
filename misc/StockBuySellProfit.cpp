#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    vector<ll>v;
    ll n,money,k=0;
    cin>>n>>money;
    for (ll i = 0; i < n; i++)
    {
        ll t;
        cin>>t;
        v.push_back(t);
    }
    for(ll i = 0; i < n; i++)
    {
        while(i<n-1&&v[i]>=v[i+1])
            i++;
        if(i==n-1)
            break;
        //buy
        /*
        //for multiple stock buys
        k=money/v[i];
        money=money%v[i];
        /**/
        // for single stock buy
        money-=v[i];
        printf("k=%lld b=%lld i=%lld\n", k,b,i);
        while(i<n-1&&v[i]<v[i+1])
            i++;
        //sell
        /*
        // for multiple stock sells
        money+=k*v[i];
        k=0;
        /**/
        // for single stock sell
        money+=v[i];/**/
        printf("k=%lld b=%lld i=%lld\n", k,b,i);
    }
    cout<<(money)<<endl;
    return 0;
}
