#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i,t,k;
	vector<pair<int,int>>v;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>t;
		v.push_back(pair<int,int>(t,i+1));
	}
	sort(v.begin(),v.end());
	cout<<v[n-k].first<<endl;
	i=n-1;
	while(k--)
	{
		cout<<v[i].second<<" ";
		i--;
	}
	cout<<endl;
	return 0;
}
