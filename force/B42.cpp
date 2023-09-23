#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll n,m,s,f,t=1,move;
    char ch;
    cin>>n>>m>>s>>f;
    if(s>f)
    {
        move=-1;
        ch='L';
    }
    else
    {
        move=1;
        ch='R';
    }
    for(ll i = 1; i <= m; i++)
    {
        ll ti,l,r;
        cin>>ti>>l>>r;
        if(s==f)
            break;
        while(t<ti&&s!=f)
        {
            cout<<ch;
            s+=move;
            t++;
        }
        if(s==f)
            break;
        if((s>=l&&s<=r)||(s+move>=l&&s+move<=r))
            cout<<'X';
        else
        {
            cout<<ch;
            s+=move;
        }
        t++;
    }
    while(s!=f)
    {
        cout<<ch;
        s+=move;
    }
    return 0;
}
