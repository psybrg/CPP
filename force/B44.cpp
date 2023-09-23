#include <iostream>
#define ll long long int
using namespace std;
ll n,s;
void dfs(ll num,ll digit1,ll digit2)
{
	if (num<=n)
	{
		s++;
		if (num<=n/10)
			if (digit1!=digit2)
			{
				dfs(num*10+digit1,digit1,digit2);
				dfs(num*10+digit2,digit1,digit2);
			}
			else
				for (ll i=0;i<10;i++)
					dfs(num*10+i,digit1,i);
	}
}
int main()
{
	cin>>n;
	for (ll i=1;i<=9;i++)
		dfs(i,i,i);
	cout<<s<<endl;
	return 0;
}
