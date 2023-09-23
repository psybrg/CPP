#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int i=0,n,s,s1,s2=1;
    cin>>n>>s;
    vector<int>max(n,0);
    vector<int>min(n,0);
    if(s>0)
    {
        min[0]=1;
        s2=s-1;
    }
    else
    {
        if(n==1)
        {
            cout<<0<<" "<<0<<endl;
            return 0;
        }
        else
        {
            cout<<-1<<" "<<-1<<endl;
            return 0;
        }
    }
    s1=s;
    while(s1>0&&i<n)
    {
        if(s1>=9)
        {
            max[i]=9;
            s1-=9;
        }
        else
        {
            max[i]=s1;
            s1-=s1;
        }
        i++;
    }
    i=n-1;
    while(s2>0&&i>=0)
    {
        if(i==0)
        {
            if(s2>=9)
            {
                min[i]+=8;
                s2-=8;
            }
            else if(s2>0)
            {
                min[i]+=s2;
                s2-=s2;
            }
        }
        else if(s2>=9)
        {
            min[i]=9;
            s2-=9;
        }
        else
        {
            min[i]+=s2;
            s2-=s2;
        }
        i--;
    }
    if(s1!=0||s2!=0)
    {
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    for(i=0;i<n;i++)
        cout<<min[i];
    cout<<" ";
    for(i=0;i<n;i++)
        cout<<max[i];
    cout<<endl;
    return 0;
}
