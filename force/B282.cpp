#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s="";
    int i,n,p,q,d=0;
    vector<int>a,b;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p>>q;
        a.push_back(p);
        b.push_back(q);
    }
    for(i=0;i<n;i++)
    {
        if(d+a[i]<500)
        {
            d+=a[i];
            s+="A";
        }
        else
        {
            d-=b[i];
            s+="G";
        }
    }
    cout<<s<<endl;
    return 0;
}
