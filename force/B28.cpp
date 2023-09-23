#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll count(ll x)
{
    ll l=0;
    while(x!=0)
    {
        l+=x%2;
        x/=2;
    }
    return l;
}
int main(int argc, char const *argv[])
{
    ll na,ma,nb,mb,mx=0,x=0,y=0;
    cin>>na>>ma;
    vector<ll>va,vb;
    for (size_t i = 0; i < na; i++) {
        string s;
        cin>>s;
        va.push_back(stoll(s,NULL,2));
    }
    cin>>nb>>mb;
    for (size_t i = 0; i < nb; i++) {
        string s;
        cin>>s;
        vb.push_back(stoll(s,NULL,2));
    }
    for (ll r = -63; r < 64; r++)
    {
        ll i=0,j=nb-1;
        while(i<na)
        {
            ll p=i,q=j,s=0;
            while(p<na&&q<nb)
            {
                if(r>=0)
                    s+=count((va[p]>>r)&vb[q]);
                else
                    s+=count((va[p]<<(-r))&vb[q]);
                p++;
                q++;
            }
            if(mx<s)
            {
                mx=s;
                y=r;
                x=j-i;
            }
            if(j==0)
                i++;
            else
                j--;
        }
    }
    cout<<x<<" "<<(y-ma+mb)<<endl;
    return 0;
}
