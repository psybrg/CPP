#include<bits/stdc++.h>
#include<cmath>
using namespace std;
vector<int>isprime,spf,prime;
int MAX=1000009;
void goSieve()
{
	isprime[0]=isprime[1]=0;
	for(int i=2;i<MAX;i++)
	{
		if(isprime[i]==1)
		{
			prime.push_back(i);
			spf[i]=i;
		}
		for(int j=0;j<prime.size()&&i*prime[j]<MAX&&prime[j]<=spf[i];j++)
		{
			isprime[i*prime[j]]=0;
			spf[i*prime[j]]=prime[j];
		}
	}
}
int main()
{
	int i,t;
	for(i=0;i<MAX;i++)
	{
		isprime.push_back(1);
		spf.push_back(2);
	}
	goSieve();
	cin>>t;
	long long int arr[t];
	for(i=0;i<t;i++)
		cin>>arr[i];
	for(i=0;i<t;i++)
	{
		long long int tmp=(long long int)sqrt(arr[i]);
		if(tmp*tmp==arr[i]&&arr[i]>1)
		{
			if(isprime[tmp]==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
				printf("NO\n");
	}
	/*
	for(i=0;i<prime.size();i++)
	{
		printf("%d\t",prime[i]);
	}/**/
	return 0;
}
