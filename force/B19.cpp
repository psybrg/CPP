#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll p,d,i=1;
    cin>>p>>d;
    while(i<=p)
    {
        ll digit=(p/i)%10;
        ll bs=(digit+1)*i;
        if(digit<9)
        {
            if(d>=bs)
            {
                p-=bs;
                d-=bs;
            }
            else
                break;
        }
        i*=10;
    }
    cout<<p<<endl;
    return 0;
}
