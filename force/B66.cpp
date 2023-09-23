#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,t,max=1;
    cin>>n;
    vector<int>d(n,0);
    vector<int>a(n,0);
    vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    a[0]=1;
    d[n-1]=1;
    for(i=1;i<n;i++)
    {
        if(v[i]>=v[i-1])
            a[i]=1+a[i-1];
        else
            a[i]=1;
        if(v[n-i-1]>=v[n-i])
            d[n-i-1]=1+d[n-i];
        else
            d[n-i-1]=1;
        
    }
    for(i=0;i<n;i++)
    {
        t=a[i]+d[i];
        if(max<t)
            max=t;
    }
    cout<<max-1<<endl;
}