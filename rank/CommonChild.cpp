#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int i,j,n=a.length();
	vector<vector<int>>arr(n+1,vector<int>(n+1,0));
	
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
				arr[i][j]=0;
			else if(a[i-1]==b[j-1])
			{	
				//cout<<a[i-1]<<"\t"<<b[j-1]<<endl;
				arr[i][j]=arr[i-1][j-1]+1;
			}
			else
				arr[i][j]=(arr[i-1][j]>arr[i][j-1])?arr[i-1][j]:arr[i][j-1];
			cout<<i<<"\t"<<j<<endl;
			//cout<<n<<"\t"<<sizeof(long double)<<"\tfuck\n";
		}
	cout<<arr[n][n]<<endl;
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
