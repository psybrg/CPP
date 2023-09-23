#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int invMul(long long int a,long long int b)
{
    long int b0 = b, t, q;
	long int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
int main (int argc, char const* argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		long int i,n,k,m,m1;
		cin>>n>>k>>m;
		vector<long long int>n0,n1;
		n0.push_back(n);
		n1.push_back(n-1);
		for(i=0;i<=18;i++)
		{
			n0.push_back((n0[i]*n0[i])%MOD);
			n1.push_back((n1[i]*n1[i])%MOD);
		}
		if(m%2==1)
			m1=1+m/2;
		else
			m1=1+(m-1)/2;
		long long int nr=1,dr=1,p,q,ans;
		for(i=n0.size()-1;i>=0;i--)
		{
			if(m1>=(1<<i))
			{
				nr=(nr*n1[i])%MOD;
				dr=(dr*n0[i])%MOD;
				m1=m1-(1<<i);
			}
		}
		if(m%2==1)
		{
			q=dr;
			p=(dr-nr+MOD)%MOD;
		}
		else
		{
			q=dr;
			p=(dr-nr+MOD)%MOD;
			long long int pnr=1,pdr=1,m2=m/2;
			for(i=n0.size()-1;i>=0;i--)
			{
				if(m2>=(1<<i))
				{
					pnr=(pnr*n1[i])%MOD;
					pdr=(pdr*n0[i])%MOD;
					m2=m2-(1<<i);
				}
			}
			pdr=(pdr*(n+k))%MOD;
			p=((p*pdr)%MOD+(q*pnr)%MOD)%MOD;
			q=(q*pdr)%MOD;
		}
		//cout<<p<<"/"<<q<<endl;
		ans=(p*invMul(q,MOD))%MOD;
		cout<<ans<<endl;
	}
	return 0;
}

