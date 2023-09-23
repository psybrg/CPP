#include<bits/stdc++.h>
#define ull long long int
using namespace std;
ull sd(ull n)
{
    ull a=0;
    while(n>0)
    {
        a+=n%10;
        n/=10;
    }
    return a;
}
ull brute(ull l, ull r, ull n)
{
    for(ull i=l;i<=r;i++)
    {
        ull z=i*i+i*sd(i);
        if(z==n)
            return i;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    ull lo=0,hi,n,m,z,lg;
    int a=0;
    cin>>n;
    hi=1+sqrt(n);
    lg=2*log2(n);
    //cout<<hi<<endl<<lg<<endl;
    while(lo<=hi)
    {
        if(hi-lo>lg)
        {
            m=lo+(hi-lo)/2;
            z=m*m+m*sd(m);
            if(z>n)
                hi=m;
            else if(z<n)
                lo=m;
            else
                break;
        }
        else
        {
            m=brute(lo,hi,n);
            break;
        }
        //cout<<lo<<"\t"<<m<<"\t"<<hi<<"\n";
    }
    cout<<m;
    cout<<endl;
    return 0;
}
