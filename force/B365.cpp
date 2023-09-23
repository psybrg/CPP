#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,s=1,mx=1;
    cin>>n;
    vector<int>v(n,0);
    for(i=0;i<n;i++)
        cin>>v[i];
    for(i=1;i<n;i++)
    {
        if(i==1&&(v[i]==v[i-1]))
            s++;
        else if(v[i]==(v[i-1]+v[i-2]))
            s++;
        else s=2;
        if(mx<s)
        mx=s;
    }
    cout<<mx<<endl;
    return 0;
}
