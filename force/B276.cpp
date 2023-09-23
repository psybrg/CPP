#include <bits/stdc++.h>
using namespace std;
int isSymm(vector<int>v,int t)
{
    int i;
    if(t%2==0)
    {
        for(i=0;i<v.size();i++)
            if(v[i]%2!=0)
                return 0;
        return 1;
    }
    else
    {
        int f=0;
        for(i=0;i<v.size();i++)
            if(v[i]%2!=0)
                f++;
        if(f==1)
            return 1;
        else
            return 0;
    }
}
void print(vector<int>v)
{
    for (size_t i = 0; i < v.size(); i++)
        if(v[i]>0)
            printf("%d ",v[i]);
    cout<<endl;
}
void trim(vector<int>&v)
{
    int i;
    for(i=0;i<v.size();i++)
    {
        if(v[i]%2==1)
        {
            v[i]--;
            return;
        }
    }
}
int main(int argc, char const *argv[]) {
    string s;
    cin>>s;
    int i,t,f=1,n=s.length();
    t=n;
    vector<int>v(26,0);
    for(i=0;i<n;i++)
    {
        v[s[i]-97]++;
    }
    while(t>0)
    {
        if(isSymm(v,t))
        {
            if(f==1)
                cout<<"First"<<endl;
            else
                cout<<"Second"<<endl;
            break;
        }
        else
        {
            trim(v);
            //print(v);
            t--;
            f=(f+1)%2;
        }
    }
    return 0;
}
