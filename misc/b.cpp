#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,n;
	cin>>n;
	set<pair<int,int>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		s.insert(pair<int,int>(a,b));
	}
	for(set<pair<int,int>>::iterator i=s.begin();i!=s.end();i++)
	{
		cout<<i->first<<"\t"<<i->second<<endl;
	}
	return 0;
}
/*
vector<int>S(v,0);
vector<int>P(v,-1);
vector<int>D(v,INT_MAX);
D[src]=0;
set<pair<int,int>>s;
for(int i=0;i<v;i++)
{
    if(i!=src)
    s.insert(pair<int,int>(INT_MAX,i));
    else
    s.insert(pair<int,int>(0,src));
}
while(!s.empty())
{
    set<pair<int,int>>::iterator x=s.begin();
    int cv=x->second;
    S[cv]=1;
    s.erase(x);
    for(int i=0;i<v;i++)
    if(G[cv][i]!=0&&S[i]==0)
		if(D[i]<(D[cv]+G[cv][i]))
		{
            D[i]=D[cv]+G[cv][i];
            P[i]=cv;
        }
}  
/**/