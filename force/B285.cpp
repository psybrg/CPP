#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int i,n,s,t,x,ans=0,m,s1;
    vector<int>v;
    v.push_back(0);
    cin>>n>>s>>t;
    m=n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
        if(s==x)
            s1=i+1;
    }
    while(m>=0&&v[s1]!=t)
    {
        //cout<<s1<<"\t"<<v[s1]<<endl;
        s1=v[s1];
        ans++;
        m--;
    }
    //cout<<m<<endl;
    if(m>0)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
