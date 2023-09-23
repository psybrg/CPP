#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,n,r;
    cin>>n;
    vector<int>v[100001];
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    vector<int>ans[2];
    for(i=0;i<100001;i++)
    {
        if(v[i].size()>1)
            for(j=1,r=v[i][1]-v[i][0];j<v[i].size();j++)
            {
                if(v[i][j]-v[i][j-1]!=r)
                    break;
                if(j==v[i].size()-1)
                {
                    ans[0].push_back(i);
                    ans[1].push_back(r);
                }
            }
        else if(v[i].size()==1)
        {
            ans[0].push_back(i);
            ans[1].push_back(0);
        }
    }
    cout<<ans[0].size()<<endl;
    for(i=0;i<ans[0].size();i++)
        cout<<ans[0][i]<<" "<<ans[1][i]<<endl;
    return 0;
}
