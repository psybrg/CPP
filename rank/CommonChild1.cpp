#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int i,j,n=a.length();
	vector<int>dn(5009,0);
	for(i=0;i<=n;i++)
	{
		vector<int>up(dn);
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
				dn[j]=0;
			else if(a[i-1]==b[j-1])
				dn[j]=up[j-1]+1;
			else
				dn[j]=(up[j]>dn[j-1])?up[j]:dn[j-1];
		}
	}
	cout<<dn[n]<<endl;
	/*
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			cout<<arr[i][j]<<"\t";
		cout<<endl;
	}
	/**/
	return 0;
}
