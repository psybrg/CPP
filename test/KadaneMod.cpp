#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int i,n,t,s,q,mx;
    cin>>n;
    std::vector<int> v(n,0);
    for (i = 0; i < n ; i++)
        cin>>v[i];
    s=v[0];
    mx=q=v[0]*v[0];
    for(i=1;i<n;i++)
    {
        if(s+v[i]<v[i])
        {
            if(q+v[i]<v[i]*v[i])
                q=v[i]*v[i];
            else
                q+=v[i];
            s=v[i];
        }
        else
        {
            if(q+v[i]<s+v[i]*v[i])
                q=s+v[i]*v[i];
            else
                q+=v[i];
            s+=v[i];
        }
        if(mx<q)
            mx=q;
        cout<<s<<" "<<q<<" "<<mx<<endl;
    }
    cout<<mx<<endl;
    return 0;
}
