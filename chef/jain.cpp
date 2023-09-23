#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin>>x;
    while(x--)
    {
        int i,j,n,t;
        cin>>n;
        string s[n];
        vector<int>v(n,0);
        for(i=0;i<n;i++)
        {    
            cin>>s[i];
            for(j=0;j<s[i].length();j++)
            {
                if(s[i][j]=='a')
                    v[i]=v[i]|1;
                else if(s[i][j]=='e')
                    v[i]=v[i]|2;
                else if(s[i][j]=='i')
                    v[i]=v[i]|4;
                else if(s[i][j]=='o')
                    v[i]=v[i]|8;
                else if(s[i][j]=='u')
                    v[i]=v[i]|16;
                if(v[i]==31)
                    break;
            }
            vector<int>has(32,0);
            for(i=0;i<n;i++)
                has[v[i]]++;
            int ans=0;
            for(i=0;i<32;i++)
                for(j=i+1;j<32;j++)
                    if(i|j==31)
                        ans+=has[i]*has[j];
            cout<<ans<<endl;
        }
    }        
    return 0;
}