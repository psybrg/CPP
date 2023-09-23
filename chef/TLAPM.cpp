#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        int z=2,num=1,ans=num;
        for (int i = 1; i < x1; i++,z++)
        {
            num+=z;
            // cout<<num<<"\t";
        }
        z--;
        for (int i = 1; i < y1; i++,z++)
        {
            num+=z;
            // cout<<num<<"\t";
        }

        z=x1+y1,ans=num;
        for (int i = x1; i < x2; i++,z++)
        {
            num+=z;
            ans+=num;
            // cout<<num<<"\t";
        }
        z--;
        for (int i = y1; i < y2; i++,z++)
        {
            num+=z;
            ans+=num;
            // cout<<num<<"\t";
        }
        cout<<ans<<endl;
    }
    return 0;
}
