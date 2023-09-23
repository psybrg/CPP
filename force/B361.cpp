#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long int n,k;
	cin>>n>>k;
	vector<int>v;
	for(int i=0;i<n;i++)
		v.push_back(i+1);
	if(k>=n)
		cout<<-1<<endl;
	else
	{
		long int t=(n-k)/2,idx;
		if((n-k)%2==1)
			idx=1;
		else
			idx=n-1;
		while(t--)
		{
				long int tmp=v[idx];
				v[idx]=v[(idx+1)%n];
				v[(idx+1)%n]=tmp;
				idx=(idx+2)%n;
		}
		for (int i = 0; i < n ; ++i)
			cout<<v[i]<<" ";
	}
	return 0;
}