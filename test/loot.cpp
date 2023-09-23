#include <bits/stdc++.h>
using namespace std;
long int mem[1000000]={-1};
long int max(long int a,long int b)
{
	return a>b?a:b;
}
int rec(vector<int> vc,int i,int n)
{
	if(i>=n)
		return 0;
	if(mem[i]>0)
		return mem[i];/**/
	return mem[i]=/**/max(vc[i]+rec(vc,i+2,n),rec(vc,i+1,n));
}
int main()
{
	int i,n,t;
	std::vector<int> vc;
	printf("Enter size : ");
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;
		//printf("Enter num : ");
		vc.push_back(t);
	}

	cout<<rec(vc,0,n)<<endl;/*
	for (i = 0; i < n; ++i)
		cout<<mem[i]<<"\t"<<endl;/**/
	return 0;
}