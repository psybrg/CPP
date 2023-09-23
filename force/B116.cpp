#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int n,l,i,j,count=0;
    cin>>n>>l;
    vector<string>vs(n,".");
    for (i = 0; i < n ; i++)
        cin>>vs[i];
    for(i=0;i<n;i++)
        for(j=0;j<l;j++)
        {
            if(vs[i][j]=='P')
            {
                if(j>0&&vs[i][j-1]=='W')
                {
                    vs[i][j-1]='.';
                    count++;
                }
                else    if(i>0&&vs[i-1][j]=='W')
                {
                    vs[i-1][j]='.';
                    count++;
                }
                else    if(j<(l-1)&&vs[i][j+1]=='W')
                {
                    vs[i][j+1]='.';
                    count++;
                }
                else    if(i<(n-1)&&vs[i+1][j]=='W')
                {
                    vs[i+1][j]='.';
                    count++;
                }
            }
        }
    cout<<count<<endl;
    return 0;
}
