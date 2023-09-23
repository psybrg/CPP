#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void prnt(vector<int>v)
{
    for (size_t i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
void setmin(int min,vector<int>&v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>min)
        {
            v[i]=min;
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    setmin((v[0]>v[n-1])?v[n-1]:v[0],v);
    for(int i=2;i<n;)
    {
        int idx;
        if(v[i-1]>v[i])
            idx=i-1;
        else
            idx=i;
        setmin((v[i-2]>v[idx])?v[idx]:v[i-2],v);
        if(i==2)
        {
            setmin((v[0]>v[n-1])?v[n-1]:v[0],v);
        }
        i=idx+2;
        //prnt(v);
    }
    int mx=v[0];
    for(int i=1;i<n;i++)
    {
        if(mx<v[i])
            mx=v[i];
    }
    cout<<mx<<endl;
    return 0;
}
