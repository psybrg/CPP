#include<bits/stdc++.h>
using namespace std;
int main (int argc, char const* argv[])
{
	long int t,M=1000000000;
	cin>>t;
	while(t--)
	{
		long int xu,xl,yu,yl,a[5],cx,cy;
		cout<<"Q "<<0<<" "<<0<<endl;
		cin>>a[0];
		cout<<"Q "<<0<<" "<<M<<endl;
		cin>>a[1];
		cout<<"Q "<<M<<" "<<0<<endl;
		cin>>a[2];
		cx=(M+a[0]-a[2])/2;
		cy=(M+a[0]-a[1])/2;
		cout<<"Q "<<cx<<" "<<0<<endl;
		cin>>a[3];
		yl=(a[0]+a[3]-cx)/2;
		xl=(a[0]-a[3]+cx)/2;
		yu=2*cy-yl;
		xu=2*cx-xl;
		cout<<"A "<<xl<<" "<<yl<<" "<<xu<<" "<<yu<<endl;
		cin>>a[4];/*
		if(a[5]>0)
			continue;
		else break;/**/
	}
	return 0;
}
