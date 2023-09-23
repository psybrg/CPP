#include <bits/stdc++.h>
using namespace std;
bool opSort(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second>b.second||((a.second==b.second)&&(a.first>b.first)));
}
int main()
{
    int i,n,s=0,c=1;
    cin>>n;
    vector<pair<int,int>>v;
    for(i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        //cout<<i<<endl;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),opSort);
    for(i=0;i<n&&c>0;i++)
    {
        c+=v[i].second;
        c--;
        s+=v[i].first;
    }
    cout<<s<<endl;
    return 0;
}
