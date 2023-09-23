#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s,ans="";
    cin>>s;
    int i,j,n=s.length(),x=1;
    if(n==1)
    {
        cout<<s<<endl;
        return 0;
    }
    char ch;
    vector<pair<char,int>>v;
    for(i=1;i<n;i++)
    {
        ch=s[i-1];
        if(s[i]==s[i-1])
        {
            x++;
            continue;
        }
        v.push_back(pair<char,int>(ch,x));
        ch=s[i];
        x=1;
    }
    v.push_back(pair<char,int>(ch,x));
    for(i=0;i<v.size();i++)
        if(i==0&&v[i].second>2)
            v[i].second=2;
        else if(v[i-1].second==2&&v[i].second>1)
            v[i].second=1;
        else if(v[i].second>2)
            v[i].second=2;
    for(i=0;i<v.size();i++)
        for(j=0;j<v[i].second;j++)
            ans+=v[i].first;
    cout<<ans<<endl;
    return 0;
}