#include <bits/stdc++.h>
using namespace std;
int mag(int x)
{
    return (x>=0)?x:(-x);
}
int main(int argc, char const *argv[]) {
    int i,n,t;
    long int ans=0;
    vector<int>v;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    for(i=0;i<v.size();i++)
    {
        if(i==0)
            ans=v[i];
        else
            ans+=mag(v[i]-v[i-1]);
        ans++;
        //cout<<ans<<endl;
    }
    ans+=n-1;
    cout<<ans<<endl;
    return 0;
}
