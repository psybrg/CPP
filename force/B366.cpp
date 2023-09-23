#include <bits/stdc++.h>
using namespace std;
int mag(int n)
{
    return (n<0)?(-n):n;
}
int main(int argc, char const *argv[])
{
    int i,j,n,x,min=0x7fffffff,idx=0,t;
    cin>>n>>x;
    vector<int>v(x,0);
    for(i=0;i<n;i++)
    {
        cin>>t;
        v[i%x]+=t;
    }
    for(i=0;i<x;i++)
        if(min>v[i])
        {
            min=v[i];
            idx=i+1;
        }
    cout<<idx<<endl;/*
    for(i=0;i<x;i++)
        cout<<v[i]<<endl;
    /**/
    return 0;
}
