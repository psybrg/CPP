#include <bits/stdc++.h>
using namespace std;
int mag(int x)
{
    if(x<0)
        return (-x);
    return x;
}
int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int i,j,k,t,n=s.length(),min=0x7fffffff;
        vector<int>hash(26,0);
        vector<int>sr;
        vector<int>dom;
        for(i=0;i<n;i++)
            hash[s[i]-65]++;
        for(i=1;i<=26;i++)
            if(n%i==0)
            {
                dom.push_back(i);
                sr.push_back(n/i);
            }
        sort(hash.begin(),hash.end());
        for(i=0;i<sr.size();i++)
        {
            t=0;
            for(j=25,k=0;j>=0;j--,k++)
            {
                if(dom[i]>k)
                    t+=mag(hash[j]-sr[i]);
                else
                    t+=hash[j];
            }
            if(min>t)
                min=t;
        }
        cout<<min/2<<endl;
    }
    return 0;
}
