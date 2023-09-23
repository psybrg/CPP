/*
In this Question comparator function is learnt.
It sorts vector of pair in descending order as per the $second$ element keeping greater values of $first$ also in descending order for equal values of $second$.
Important stuff.
/**/
#include <bits/stdc++.h>
using namespace std;
bool sortBy1stInDescending(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.first>b.first;//for descending first
}
bool sortBy2ndInDescending(const pair<int,int>&a,const pair<int,int>&b)
{
    return a.second>b.second;//for descending second
//    return a.second<b.second;//for ascending second
//    return a.first<b.first;//for ascending first
}
int main()
{
    int i,n,t,k,s=0,c=1;
    cin>>n;
    vector<pair<int,int>>v;
    for(i=0;i<n;i++)
    {
        cin>>k>>t;
        v.push_back(pair<int,int>(k,t));
    }
    sort(v.begin(),v.end(),sortBy1stInDescending);
    sort(v.begin(),v.end(),sortBy2ndInDescending);
    for (i = 0; i < n ; i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;/**/
    for(i=0;i<n&&c>0;i++)
    {
        c+=v[i].second;
        c--;
        s+=v[i].first;
    }
    cout<<s<<endl;
    return 0;
}
