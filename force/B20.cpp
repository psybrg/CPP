#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll n=0, q=0;
    vector<vector<ll>>G(101,vector<ll>(101,0));
    vector<ll>x(101,0);
    vector<ll>y(101,0);
    cin>>q;
    while(q--)
    {
        ll tp, a, b;
        cin>>tp>>a>>b;
        if(tp == 2)
            cout<<(G[a][b] ? "YES\n" : "NO\n");
        else
        {
            ++n;
            x[n] = a;
            y[n] = b;
            for(int i = 1; i < n; ++i)
            {
                G[n][i] = x[i] < x[n] && x[n] < y[i] ||
                           x[i] < y[n] && y[n] < y[i];
                G[i][n] = x[n] < x[i] && x[i] < y[n] ||
                           x[n] < y[i] && y[i] < y[n];
            }
            for(int k = 1; k <= n; ++k)
                for(int i = 1; i <= n; ++i)
                    for(int j = 1; j <= n; ++j)
                        if(G[i][k] && G[k][j])
                            G[i][j] = 1;
        }
    }
    return 0;
}
