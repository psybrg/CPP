#include<bits/stdc++.h>
using namespace std;
const long long int_max = 0x7fffffff;
int main()
{
    ios::sync_with_stdio(false);
    long long t;
    cin>>t;
    while(t--)
    {
        long long e,f,n;
        cin>>e>>f>>n;
        vector<long long> p(n), w(n), dp(f - e + 1, int_max);
        dp[0] = 0;
        for (long long i = 0; i < n; i++)
            cin>>p[i]>>w[i];
        for (long long i = 0; i <= f-e; i++)
            for(long long j = 0; j < n; j++)
                if(w[j] <= i)
                    dp[i] = min(dp[i],dp[i-w[j]]+p[j]);
        if (dp[f - e] == int_max)
            cout<<"This is impossible.\n";
        else
            cout << "The minimum amount of money in the piggy-bank is "<<dp[f-e]<<".\n";
    }
    return 0;
}