#include <bits/stdc++.h>
using namespace std;
int hsh(string s)
{
    int i,ans=0;
    for(i=0;i<s.length()&&ans<134217728;i++)
    {
        int t=(int)s[i]-97;
        if(t>=0)
            ans=ans|(1<<t);
    }
    return ans;
}
int dec(int n)
{
    int i,ans=0;
    for(i=1;i<=n;i=i*2)
    {
        int t=i&n;
        if(t>0)
            ans++;
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,res;
        cin>>n;
        string s[n];
        vector<int>v;
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            v.push_back(hsh(s[i]));
        }
        //printf("hh\n");
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                res=v[i];
                continue;
            }
            res=res&v[i];
        }
        //printf("hh\n");
        cout<<dec(res)<<endl;
    }
    return 0;
}
