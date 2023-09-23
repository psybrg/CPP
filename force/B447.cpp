#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    string s;
    getline(cin,s);
    int i,n=s.length(),k,t,mx=0;
    cin>>k;
    vector<int>v;
    long int ans=0;
    for(i=0;i<26;i++)
    {
        cin>>t;
        if(mx<t)
            mx=t;
        v.push_back(t);
    }
    for(i=0;i<n;i++)
        ans+=(i+1)*v[s[i]-97];
    ans+=mx*(n*k+(k+1)*k/2);
    cout<<ans<<endl;
    return 0;
}
