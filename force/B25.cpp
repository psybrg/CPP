#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll s,k;
    vector<ll>v,rs;
    set<ll>ans;
    cin>>s>>k;
    v.push_back(0);
    rs.push_back(0);
    v.push_back(1);
    rs.push_back(1);
    while(s>v[v.size()-1])
    {
        ll n=rs.size()-1;
        if(n>=k)
            v.push_back(rs[n]-rs[n-k]);
        else
            v.push_back(rs[n]-rs[0]);
        rs.push_back(rs[rs.size()-1]+v[v.size()-1]);
    }
    ll i=v.size()-1;
    while(s>0&&i>0)
    {
        if(s>=v[i])
        {
            ans.insert(v[i]);
            s-=v[i];
        }
        i--;
    }
    ans.insert(0);
    i=ans.size();
    cout<<i<<endl;
    for (set<ll>::iterator itr = ans.begin(); itr != ans.end(); itr++)
        cout << *itr<<" ";
    cout<<endl;
    return 0;
}
