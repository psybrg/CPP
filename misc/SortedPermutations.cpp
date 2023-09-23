#include <bits/stdc++.h>
#define MOD 1000003
using namespace std;
int fact(int n)
{
	int i,f=1;
	while(n--)
		f=(f%MOD)*(n%MOD)%MOD;
	return f;
}
int main(int argc, char const *argv[])
{
	int i,n,t;
	string s;
	cin>>s;
	n=s.size();
	vector<int>f(n+1,1);
	for(i=2;i<=n;i++)
		f[i]=(i%MOD)*(f[i-1]%MOD)%MOD;
	vector<int>v(26,0);
	for(i=0;i<s.size();i++)
		v[s[i]-'a']++;
	
	return 0;
}
