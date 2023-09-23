#include <bits/stdc++.h>
using namespace std;
int mag(int n)
{
    return (n<0)?(-n):n;
}
int main(int argc, char const *argv[])
{
    int i,j,r,c,d,s,min=0x7fffffff;
    cin>>r>>c>>d;
    vector<int>arr;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            int t;
            cin>>t;
            arr.push_back(t);
        }
    sort(arr.begin(),arr.end());
    vector<int>v,f;
    v.push_back(arr[0]);
    f.push_back(1);
    for(i=1,j=0;i<arr.size();i++)
    {
        if(v[j]!=arr[i])
        {
            v.push_back(arr[i]);
            f.push_back(1);
            j++;
        }
        else
        {
            f[j]++;
        }
        if((arr[i]-arr[i-1])%d!=0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(i=0;i<v.size();i++)
    {
        s=0;
        for(j=0;j<v.size();j++)
            if(i!=j)
                s+=f[j]*mag(v[i]-v[j])/d;
        if(min>s)
            min=s;
    }
    cout<<min<<endl;/*
    for(i=0;i<v.size();i++)
        printf("%d %d   \n",v[i],f[i]);/**/
    return 0;
}
