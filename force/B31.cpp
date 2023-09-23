#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll n,d,l,idx,cd;
    cin>>n>>d>>l;
    vector<ll>v(n,1);
    if(d>0)
        idx=0;
    else
        idx=1;
    if(n%2)
        cd=1;
    else
        cd=0;
    while(idx<n&&cd!=d)
    {
        ll z;
        if(d>cd)
        {
            if(d-cd>l-1)
                z=l-1;
            else
                z=d-cd;
            cd+=z;
        }
        else
        {
            if(cd-d>l-1)
                z=l-1;
            else
                z=cd-d;
            cd-=z;
        }
        v[idx]+=z;
        idx+=2;
    }
    if(d<0&&cd>d||d>0&&cd<d)
        cout<<-1;
    else for (size_t i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
