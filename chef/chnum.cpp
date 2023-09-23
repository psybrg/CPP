#include<bits/stdc++.h>
using namespace std;
int main (int argc, char const* argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int i,n,a=0,b=0,c=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x>0)
				a++;
			else if(x<0)
				b++;
			else
				c++;
		}
		if(a>0&&b>0)
		{
			if(a>b)
				cout<<a+c<<" "<<b<<endl;
			else
				cout<<b+c<<" "<<a<<endl;
		}
		else
		{
			cout<<n<<" "<<n<<endl;
		}
	}
	return 0;
}

