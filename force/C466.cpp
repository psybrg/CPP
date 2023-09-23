#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    vector<int>v(n,0);
    vector<long long int>aug(n,0);
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        if(i==0)
            aug[i]=v[i];
        else
            aug[i]=v[i]+aug[i-1];
    }
    long long int ans=0;
    if(aug[n-1]%3!=0)
        cout<<0<<endl;
    else if(aug[n-1]==0)
    {
        long long int f=0;
        for(i=0;i<n;i++)
            if(aug[i]==0)
                f++;
        ans=(long long int )(f-1)*(long long int )(f-2)/2;
        cout<<ans<<endl;
    }
    else
    {
        int a=0;
        for(i=0;i<n;i++)
        {
            if(aug[i]==2*aug[n-1]/3)
                ans+=a;
            if(aug[i]==aug[n-1]/3)
                a++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
