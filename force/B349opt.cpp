#include <bits/stdc++.h>
using namespace std;
bool psort(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.first<b.first||((a.first==b.first)&&(a.second>b.second)));
}
int mag(int a)
{
    return a>=0?a:-a;
}
int main(int argc, char const *argv[])
{
    int i,j,n,v,u;
    string s="";
    vector<int>a;
    vector<pair<int,int>>vp;
    cin>>v;
    for(i=0;i<9;i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
        vp.push_back(pair<int,int>(t,i+1));
    }
    sort(vp.begin(),vp.end(),psort);
    n=v/vp[0].first;
    u=v%vp[0].first;
    while(n--)
        s+='0'+vp[0].second;
    //cout<<s<<endl;
    for(i=0;i<s.length();i++)
        for(j=8;j>=1;j--)
            if(a[j]<=u+a[s[i]-'1']&&(s[i]-'0')<(j+1))
            {
                u=u-mag((int)(a[j]-a[s[i]-'1']));
                s[i]='0'+j+1;
                break;
            }
    if(s=="")
        cout<<-1<<endl;
    else
        cout<<s<<endl;
    return 0;
}
