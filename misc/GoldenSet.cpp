#include <bits/stdc++.h>
using namespace std;
int rec(int n,int k)
{
	if(k==0)
		return 1;
	if(n<=0&&k>0)
		return 0;
	if(k<0)
		return 0;
	return rec(n-1,k)+rec(n-1,k-n);
}
int main()
{
	int i,n,t;
	cin>>n;
	if(n*(n+1)%4==0)
		cout<<rec(n-1,n*(n+1)/4-n)<<endl;
	else
		cout<<0<<endl;
}
