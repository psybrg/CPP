#include<bits/stdc++.h>
#define ll long long int
using namespace std;
double mag(double a)
{
    return a>0?a:-a;
}
ll gcd(ll a,ll b)
{
    if(a==0&&b>0)
        return b;
    if(b==0&&a>0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcd(a%b,b);
    return gcd(b%a,a);
}
int main(int argc, char const *argv[])
{
    ll x,y,n;
    cin>>x>>y>>n;
    if(y<=n)
    {
        ll g=gcd(x,y);
        cout<<(x/g)<<"/"<<(y/g)<<"\n";
    }
    else
    {
        ll a,b;
        double xd=x,yd=y,d=INT_MAX;
        for (ll y1 = n; y1>0; y1--)
        {
            ll x1=y1*xd/yd;
            double p=x1;
            double q=y1;
            double z=mag(xd/yd-(p+1)/q);
            if(d>=z)
            {
                d=z;
                a=x1+1;
                b=y1;
            }
            z=mag(xd/yd-p/q);
            if(d>=z)
            {
                d=z;
                a=x1;
                b=y1;
            }
            z=mag(xd/yd-(p-1)/q);
            if(d>=z)
            {
                d=z;
                a=x1-1;
                b=y1;
            }
        }
        cout<<a<<"/"<<b<<"\n";
    }
    return 0;
}
