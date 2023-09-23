#include<bits/stdc++.h>
using namespace std;
int bnxp(int n,int r)
{
	if(r==0)return 1;
	else if(r%2==0)return bnxp(n*n,r/2);
	else return n*bnxp(n*n,(r-1)/2);
}
int main()
{
	int n,r;
	cout<<"Enter n^r : ";
	cin>>n>>r;
	cout<<bnxp(n,r)<<endl;
}
