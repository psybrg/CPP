#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>q;
        for (int i = 0; i < k; i++)
        {
            int z;
            cin>>z;
            q.push_back(z);
        }
        int d=0;
        for (int i = 1; i < n; i++)
        {
            if(s[i]!=s[i-1])
                d++;
            else
                d+=2;
        }
        for (int i = 0; i < k; i++)
        {
            if(k%2==1)
            {
                int p=q[i]-1;
                s[p]='1'-s[p]+'0';
                if(p<k-1)
                {
                    if(s[p]==s[p+1])
                        d++;
                    else
                        d--;
                }
                if(p>0)
                {
                    if(s[p]==s[p-1])
                        d++;
                    else
                        d--;
                }
            }
            cout<<d<<endl;
        }
    }
    return 0;
}
