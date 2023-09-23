
				dp[i]=dp[i-1]+(hsah[kx[i-1]]-1)*pow(A.size(),B-i);
			dp[i]=dp[i-1]+hsah[kx[i-1]]*pow(A.size(),B-i);
			dp[i]=dp[i-1]+hsah[kx[i-1]]*pow(A.size(),B-i);
			else
			hsah[i]--;
			if(check(A))
			return (A.size()-1)*pow(A.size(),B-1);
			return A.size();
			return pow(A.size(),B);}
			return true;
		A.push_back(t);
		cin>>t;
		cout<<dp[i]<<"\t";
		else
		else
		else if(check(A))
		hsah[A[i]]=1;
		hsah[i]=hsah[i]+hsah[i-1];
		if(A[i]==0)
		if(B==1)
		if(hsah[i]>0)
		if(i==1)
		kx.insert(kx.begin(),t%10);
		return 0;
		return hsah[C];
		t/=10;
	cin>>B>>C;
	cin>>n;
	cout<<endl;
	cout<<func(A,B,C);
	else if(B==1)
	else if(B>kx.size())
	for(i=0;i<A.size();i++)
	for(i=0;i<hsah.size();i++)
	for(i=0;i<n;i++)
	for(i=1;i<=kx.size();i++)
	for(i=1;i<hsah.size();i++)
	for(int i=0;i<A.size();i++)
	if(B<kx.size())
	long long int i,n,t,B,C;
	long long int i,t=C;
	return 0;
	return dp[B];
	return false;
	vector<int> A;
	vector<int>dp(B+1,0);
	vector<int>hsah(10,0);
	vector<int>kx;
	while(t>0)
	{
	{
	{
	{
	}
	}
	}
#include <bits/stdc++.h>
bool check(vector<int>&A)
int main(int argC, char const *argv[])
long long func(vector<int>&A,int B,int C)
using namespace std;
{
{
{
}
}
}
