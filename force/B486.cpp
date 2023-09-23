#include <bits/stdc++.h>
using namespace std;
int m,n;
void process(vector<vector<int>>&v,int r,int c)
{

    for (size_t k = 0; k < n; k++)
        v[r][k]=0;
    for (size_t k = 0; k < m; k++)
        v[k][c]=0;
}
int main(int argc, char const *argv[])
{
    int i,j;
    cin>>m>>n;
    int c[m][n],b[m][n];
    int up[m],dn[n];
    vector<vector<int>>a(m,vector<int>(n,1));
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            cin>>b[i][j];
            if(b[i][j]==0)
                process(a,i,j);
        }
    for(i=0;i<m;i++)
    {
        int s=0;
        for(j=0;j<n;j++)
            s=s|a[i][j];
        up[i]=s;
    }
    for(i=0;i<n;i++)
    {
        int s=0;
        for(j=0;j<m;j++)
            s=s|a[j][i];
        dn[i]=s;
    }
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            c[i][j]=up[i]|dn[j];
    int flag=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(b[i][j]!=c[i][j])
            {
                printf("NO\n");/*
                for(i=0;i<m;i++)
                {
                    for(j=0;j<n;j++)
                        cout<<a[i][j]<<" ";
                    cout<<endl;
                }/**/
                return 0;
            }
    printf("YES\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
