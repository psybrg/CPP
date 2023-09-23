#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,int>a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a[x]++;
        }
        int max=0;
        for(auto i=a.begin();i!=a.end();i++)
        {
            if(max<i->second)
            {
                max=i->second;
            }
        }
        if(n>1&&max<2)
            cout<<-1;
        else if(n==max)
            cout<<0;
        else
            cout<<(n-max/2);
        cout<<"\n";
    }
    return 0;
}