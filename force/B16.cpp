#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
vector< vector<int> > gf(101);
vector<int> color (101,-1);
void dfs(int node){
    for(int child :gf[node]){
        if(color[node]==color[child]){++ans;color[child]=2;}
        if(color[child]==-1){color[child]=!color[node];dfs(child);}
    }
}
int main()
{
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        gf[b].push_back(a);
        gf[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            color[i]=1;
            dfs(i);
        }
    }
    ans+=(n-ans)%2 ;
    cout<<ans<<endl;
    return 0;
}
