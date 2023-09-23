#include<bits/stdc++.h>
using namespace std;
void rec(vector<vector<pair<int,int>>>&G,int src,int dst,
		vector<bool>&visited,vector<int>&path, int &pi,int s,int k) 
{
	visited[src] = true; 
	path[pi] = src; 
	pi++;
	if (src == dst) 
	{ 
		for (int i = 0; i<pi; i++) 
			cout << path[i] << " ";
		cout<<"\t>>>"<<s<<"\t>>>"<<k;
		cout << endl; 
	} 
	else
		for (int i=0;i<G[src].size(); ++i) 
			if (!visited[G[src][i].first])
				rec(G,G[src][i].first,dst,visited,path,pi,s+G[src][i].second,k+1);
	pi--; 
	visited[src] = false; 
}
void print(vector<vector<pair<int,int>>>&G,int src, int dst) 
{  
	vector<bool>visited(G.size(),false);
	vector<int>path(G.size());
	int i = 0;
	rec(G,src, dst, visited, path, i,0,0); 
}
int main() 
{
	int n,s,d,k,a,b,c;
	cin>>n;
	vector<vector<pair<int,int>>>G(n);
	while(1)
	{
		cin>>a>>b>>c;
		if(a<0||b<0||c<0)
			break;
		G[a].push_back(pair<int,int>(b,c));
	}
	cin>>s>>d>>k;
	print(G,s,d);
	cout<<"\n\nBYE!!\n\n";
	return 0; 
} 
