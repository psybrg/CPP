#include<bits/stdc++.h>
using namespace std;
int mag(int a)
{
    a=(a>=0)?a:(-a);
    if(a>13)
        a=26-a;
    return a;
}
int min2(int x,int y)
{
    return x<y?x:y;
}
int main(int argc, char const *argv[])
{
    int i,n,t,s=0,x=0,reset=0,z=0;
    string st;
    cin>>n>>t;
    cin>>st;
    vector<int>v;
    vector<int>vc(n/2,0);
    if(t>n/2)
        t=n+1-t;
    if(st.length()<=1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<n/2;i++)
    {
        x=mag(st[i]-st[n-1-i]);
        if(x>0)
        {
            s+=x;
            v.push_back(1);
        }
        else
        {
            v.push_back(0);
        }
    }
    for(i=t-1,reset=1;i<n/2;i++)
    {
        if(i==t-1)
            vc[i]=0;

        else if(v[i]==1)
        {
            vc[i]=vc[i-1]+reset;
            reset=1;
            x=vc[i];
        }
        else
        {
            vc[i]=vc[i-1];
            reset++;
        }
    }
    for(i=t-1,reset=1;i>=0;i--)
    {
        if(i==t-1)
            vc[i]=0;

        else if(v[i]==1)
        {
            vc[i]=vc[i+1]+reset;
            reset=1;;
            x=vc[i];
        }
        else
        {
            vc[i]=vc[i+1];
            reset++;
        }
    }/*
    for(i=0;i<n/2;i++)
        cout<<v[i];
    cout<<endl;
    for(i=0;i<n/2;i++)
        cout<<vc[i]<<" ";
    cout<<endl;
    printf("\n%d %d %d\n",s,s+2*vc[0]+vc[n/2-1],s+vc[0]+2*vc[n/2-1]);/**/
    cout<<min2(s+2*vc[0]+vc[n/2-1],s+2*vc[n/2-1]+vc[0])<<endl;
    return 0;
}