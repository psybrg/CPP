#include<bits/stdc++.h>
using namespace std;
long long int fun(long long int n,long long int k)
{
	long long int i=1,s=0,r,q;
		while(n>0)
		{
			if(i==1)
			{
				q=n%10;
				if(q>k)
				{
					q=k;
					s+=k;
				}
				else
					s+=q;
			}
			else
			{
				r=n%10;
				if(r>q)
					s=s*10+k;
				else
				{
					s=s+r*i;
					q=r;
				}
			}		
			i*=10;
			n=n/10;
		}
	return s;
}
int main (int argc, char const* argv[])
{
	int x;
	cin>>x;
	while(x--)
	{
		long long int n,k;	
		cin>>n>>k;
		cout<<fun(n,k)<<endl;
	}
	return 0;
}

