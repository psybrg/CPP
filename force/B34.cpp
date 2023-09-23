#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,m,t,ans=0;
    vector<int>v;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for(i=0,j=0;j<m&&i<n;i++)
    {
        if(v[i]<0)
        {
            ans+=-(v[i]);
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
