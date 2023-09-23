#include<bits/stdc++.h>
using namespace std;
int kadane(vector<int>arr)
{
	int i,s=arr[0],mx=arr[0];
	for(i=1;i<arr.size();i++)
	{
		s=(arr[i]>(s+arr[i])?arr[i]:(s+arr[i]));
		mx=(mx>s)?mx:s;
	}
	return mx;
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
	cout<<kadane(v)<<endl;
	return 1;
}
