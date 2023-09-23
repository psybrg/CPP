#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll x;
	cin >> x;
	while(x)
	{
		ll mx=0, area=0;
		vector<ll> v(x);
		for (ll i = 0; i < x; i++)
		{
			cin >> v[i];
		}
		stack<ll> stk;
		ll i = 0;
		while(i<x)
		{
			if(stk.empty() || v[stk.top()] <= v[i])
			{
				stk.push(i++);
			}
			else
			{
				ll top = stk.top();
				stk.pop();
				area = v[top] * (stk.empty() ? i : i - stk.top() - 1);
				mx = mx < area ? area : mx;
			}
		}
		while(!stk.empty())
		{
			ll top = stk.top();
			stk.pop();
			area = v[top] * (stk.empty() ? i : i - stk.top() - 1);
			mx = mx < area ? area : mx;
		}
		cout << mx << "\n";
		cin >> x;
	}
	return 0;
}