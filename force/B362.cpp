#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int i,t,n,m;
    cin>>n>>m;
    if(m==0)
    {
        cout<<"YES\n";
        return 0;
    }
    vector<int>v;
    for(i=0;i<m;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    if(v[0]==1||v[v.size()-1]==n)
        cout<<"NO\n";
    else
    {
        for(i=1;i<m-1;i++)
        {
            if(((v[i-1]+1)==v[i])&&(v[i]==(v[i+1]-1)))
            {
                cout<<"NO\n";
                return 0;
            }
        }
        cout<<"YES\n";
    }
    return 0;
}
