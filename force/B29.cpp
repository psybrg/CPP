#include<bits/stdc++.h>
using namespace std;
int check(vector<set<int>>&g)
{
    vector<pair<int,int>>vp;
    for(int i=1;i<g.size();i++)
    {
        if(g[i].size()==1)
        {
            vp.push_back(pair<int,int>(i,*g[i].begin()));
            g[i].erase(*g[i].begin());
        }
    }
    for(int i=0;i<vp.size();i++)
    {
        g[vp[i].second].erase(vp[i].first);
    }
    if(vp.size()>0)
        return 1;
    return 0;
}
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
    vector<set<int>>g(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].insert(y);
        g[y].insert(x);
    }
    int ans=0;
    while(check(g)==1)
        ans++;
    cout<<ans<<endl;
	return 0;
}
