//This program finds Longest Contiguous LargestSum Subarray in O(n)
#include<bits/stdc++.h>
using namespace std;
vector<int> kadane(vector<int>A)
{
	int i,s=A[0],mx=A[0],hd=0,tl=0,tlx=0,hdx=0;
	vector<pair<int,int>>v;
	vector<int>ans;
	v.push_back(make_pair(hdx,tlx));
	for(i=1;i<A.size();i++)
	{
		if(A[i]<=s+A[i])
		{	
			s+=A[i];
			tl=i;
		}
		else 
		{
			s=A[i];
			hd=i;
			tl=i;
		}
		if(mx<=s)
		{
			mx=s;
			hdx=hd;
			tlx=tl;
		}
		cout<<s<<" and "<<mx<<endl;
		if(mx==s)
			//Storing segments with maxima
			v.push_back(make_pair(hdx,tlx));
	}
	//KADANE algo ends here and segments with maxima are stored
	for(i=0;i<v.size();i++)
	cout<<v[i].first<<" ::>> "<<v[i].second<<endl;
	hdx=v[0].first;
	tlx=v[0].second;
	for(i=1;i<v.size();i++)
		if((tlx-hdx)<(v[i].second-v[i].first))
		{
			tlx=v[i].second;
			hdx=v[i].first;
		}
	cout<<endl<<hdx<<":::>>>"<<tlx<<endl<<endl;
	for(i=hdx;i<=tlx;i++)
		ans.push_back(A[i]);	
	return ans;
}
int main()
{
	int i,n,t;
	cin>>n;
	vector<int>v;
	for(i=0;i<n;i++)
	{
		cin>>t;
		v.push_back(t);
	}
	//cout<<kadane(v)<<endl;
	vector<int>ans=kadane(v);
	for(i=0;i<ans.size();i++)
		cout<<ans[i]<<"\t";
	cout<<endl;
	return 1;
}
