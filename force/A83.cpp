#include <bits/stdc++.h>
#define ll long long int
using namespace std;

template <typename T>
void prnt(vector<T>v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<"\t";
	cout<<endl;
}

int main()
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n,0);
    for(ll i = 0; i < n; i++)
        cin>>a[i];
    for(ll i = 1; i < n; i++)
    {
        if(a[i]==a[i-1])
        {
            b[i] = b[i-1] + 1;
            b[i-1] = 0;
        }
    }
    ll s = 0;
    for(ll i = 0; i < n; i++ )
    {
        s += b[i]*(b[i]+1)/2;
    }
    cout<<(s+n)<<endl;
    return 0;
}
