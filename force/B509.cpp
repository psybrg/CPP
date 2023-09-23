#include <bits/stdc++.h>
using namespace std;
int mag(int x)
{
    return (x>=0)?x:(-x);
}
int main(int argc, char const *argv[]) {
    int n,k,i,j;
    cin>>n>>k;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>j;
        v.push_back(j);
    }
    for(i=1;i<n;i++)
        for(j=0;j<i;j++)
            if(mag(v[i]-v[j])>k)
            {
                cout<<"NO\n";
                return 0;
            }
    cout<<"YES\n";
    for (i = 0; i < n; i++)
    {
        for(j=0;j<v[i];j++)
            cout<<(1+(j%k))<<" ";
        cout<<endl;
    }
    return 0;
}
