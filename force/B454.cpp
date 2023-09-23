#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int i,n,t;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    int f=1,b=1;
    for(i=v.size()-1;i>0;i--)
    {
        if(v[i]>=v[i-1])
            b++;
        else
            break;
    }
    for(i=1;i<v.size();i++)
    {
        if(v[i]>=v[i-1])
            f++;
        else
            break;
    }
    //cout<<f<<"\t"<<b<<endl;
    if((b+f)==v.size())
    {
        if(v[0]<v[v.size()-1])
            cout<<-1<<endl;
        else
            cout<<b<<endl;
    }
    else if((b+f)>=v.size())
    {
        if(b==f)
            cout<<0<<endl;
        else
            cout<<-1<<endl;
    }
    else
        cout<<-1<<endl;
    return 0;
}
