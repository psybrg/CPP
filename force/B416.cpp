#include<bits/stdc++.h>
using namespace std;
int maxm(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int r,i,j,c;
    cin>>r>>c;
    vector<vector<int>>dp(r+1,vector<int>(c+1,0));
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin>>dp[i+1][j+1];
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            dp[i][j]=dp[i][j]+maxm(dp[i-1][j],dp[i][j-1]);
    for(i=1;i<=r;i++)
        cout<<dp[i][c]<<" ";
    cout<<endl;
}