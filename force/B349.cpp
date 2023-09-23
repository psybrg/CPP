#include<bits/stdc++.h>
using namespace std;
bool psort(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.first<b.first||((a.first==b.first)&&(a.second>b.second)));
}
vector<int>max(vector<int>a,vector<int>b,int c)
{
    vector<int>x(b);
    x[c]++;
    x[9]++;
    if(a[9]>x[9])
    {
        vector<int>ans(a);
        return ans;
    }
    else if(a[9]<x[9])
    {
        vector<int>ans(x);
        return ans;
    }
    else 
    {
        for(int i=8;i>=0;i--)
            if(a[i]>x[i])
            {
                vector<int>ans(a);
                return ans;
            }
            else if(a[i]<x[i])
            {
                vector<int>ans(x);
                return ans;
            }
    }
    return a;
}
int main(int argc, char const *argv[])
{
    int i,j,n,v;
    string s="";
    vector<int>a;
    cin>>v;
    for(i=0;i<9;i++)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    vector<vector<int>>dp(v+1,vector<int>(10,0));
    for(i=0;i<=v;i++)
        for(j=0;j<9;j++)
            if(i>=a[j])
                dp[i]=max(dp[i],dp[i-a[j]],j);
    for(i=8;i>=0;i--)
        for(j=0;j<dp[v][i];j++)
            s+='1'+i;
    if(s=="")
        cout<<-1<<endl;
    else    
        cout<<s<<endl;
    return 0;
}