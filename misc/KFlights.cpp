#include<bits/stdc++.h>
using namespace std;
void rec(vector<vector<pair<int,int>>>&G,int src,int dst, vector<bool>&visited,vector<int>&path, int &pi,int s,int k,int K) 
{
	cout<<src<<"\t";
    visited[src] = true;
    if (src == dst&&k<(K+2)) 
        path.push_back(s);
    else
        for (int i=0;i<G[src].size(); ++i) 
            if (!visited[G[src][i].first])
                rec(G,G[src][i].first,dst,visited,path,pi,s+G[src][i].second,k+1,K);
    visited[src] = false; 
}
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
{
    vector<bool>visited(n,false);
	vector<int>path;
	int i = 0;
    vector<vector<pair<int,int>>>G(n);
    for(int j=0;j<flights.size();j++)
        G[flights[j][0]].push_back(pair<int,int>(flights[j][1],flights[j][2]));
	rec(G,src, dst, visited, path, i,0,0,K);
    if(path.size()==0)
        return -1;
    int min=path[0];
	for(int j=1;j<path.size();j++)
        if(min>path[j])
            min=path[j];
    return min;
}
int main() 
{
	int n,s,d,a,b,c,k;
	cin>>n;
	vector<vector<int>>G;
	while(1)
	{
		cin>>a>>b>>c;
		if(a<0||b<0||c<0)
			break;
		G.push_back({a,b,c});
	}
	cin>>s>>d>>k;
	findCheapestPrice(n,G,s,d,k);
	return 0; 
} 