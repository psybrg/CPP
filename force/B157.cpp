#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,t;
    vector<int>v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    long /**/double ans=0,pi=3.1415926536;
    for(i=n-1;i>=0;i-=2)
    {
        if(i==0)
            ans+=pi*(v[i]*v[i]);
        else
            ans+=pi*(v[i]*v[i]-v[i-1]*v[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
