#include <bits/stdc++.h>
using namespace std;
long long int maxm(long long int a,long long int b)
{
    return (a>b)?a:b;
}
int main(int argc, char const *argv[]) {
    long long int i,n,t;
    cin>>n;
    vector<long long int>v(100003,0),dp;
    for(i=0;i<n;i++)
    {
        cin>>t;
        v[t]++;
    }
    dp.push_back(0);
    dp.push_back(v[1]);
    for(i=2;i<v.size();i++)
        dp.push_back(maxm(i*v[i]+dp[i-2],dp[i-1]));
    cout<<dp[dp.size()-1]<<endl;
    return 0;
}
