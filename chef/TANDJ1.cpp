#include<bits/stdc++.h>
using namespace std;
int mag(int a)
{
    return a>0?a:-a;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int x=mag(c-a)+mag(d-b);
        if(k>=x&&(k-x)%2==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
