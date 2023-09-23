#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll h,w,a2n=1,b2n=1;
    cin>>h>>w;

    ll hi=(ll)(w*1.25);
    while(2*a2n<=h&&2*a2n<=hi)
    {
        a2n*=2;
    }
    ll hi1=(ll)(a2n*1.25);
    hi1=(w<hi1)?w:hi1;

    hi=(ll)(h*1.25);
    while(2*b2n<=w&&2*b2n<=hi)
    {
        b2n*=2;
    }
    ll hi2=(ll)(b2n*1.25);
    hi2=(h<hi2)?h:hi2;

    if(a2n*hi1>b2n*hi2)
        cout<<a2n<<" "<<hi1<<endl;
    else
        cout<<hi2<<" "<<b2n<<endl;
    return 0;
}
