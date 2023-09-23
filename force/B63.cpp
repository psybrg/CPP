#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll n,k;
    cin>>n>>k;
    vector<ll> v(k+1,0);
    for (size_t i = 0; i < n; i++)
    {
        ll t;
        cin>>t;
        v[t]++;
    }
    for (size_t j = k-1; j>0; j--)
    {
        if(v[j]>0)
            v[j-1]+=v[j]-1;
    }
    for (size_t i = 0; i < k; i++)
        if(v[i]>0)
        {
            cout<<(v[i]+k-i-1)<<endl;
            return 0;
        }
    cout<<0<<endl;
    return 0;
}
