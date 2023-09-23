#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int s,l,d=0;
    cin>>s>>l;
    vector<int>f(l+1,0);
    for(int i=1;i<=l;i++)
    {
        if(i%2==1)
        {
            f[i]=1;
        }
        else
        {
            f[i]=2*f[i/2];
        }
        d+=f[i];
    }
    if(s>d)
        cout<<-1<<endl;
    else
    {
        vector<int>v;
        for(int i=l;i>0;i--)
        {
            if(s>=f[i])
            {
                v.push_back(i);
                s-=f[i];
            }
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
