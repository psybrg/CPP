#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    while(t--)
    {
        int i,t,n;
        cin>>n;
        vector<int>a,d,s;
        for(i=0;i<n;i++)
        {
            cin>>t;
            a.push_back(t);
        }
        for(i=0;i<n;i++)
        {
            cin>>t;
            d.push_back(t);
        }
        int mx=0,p,idx=-1;
        for(i=0;i<n;i++)
        {
            int l=(n+i-1)%n;
            int r=(n+i+1)%n;
            s.push_back(d[i]-a[r]-a[l]);
            //cout<<s[i]<<"\t";
            p=d[i]-a[r]-a[l];
            if(p>0)
            {
                if(mx<d[i])
                    mx=d[i];
            }
        }
        //cout<<endl;
        if(mx==0)
            cout<<-1<<endl;
        else
            cout<<mx<<endl;
    }
    return 0;
}
