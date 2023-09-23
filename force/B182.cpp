#include <bits/stdc++.h>
using namespace std;
long int mag(long int t)
{
	return (t>=0)?t:(-t);
}
int main(int argc, char const *argv[])
{
	long int n,d,i,t,ans=0;
	cin>>d>>n;
	vector<long int>v;
	for(i=0;i<n;i++)
	{
		cin>>t;
		v.push_back(t);
		if(i==n-1)
			continue;
		ans+=mag(d-t);
	}
	cout<<ans<<endl;
	return 0;
}