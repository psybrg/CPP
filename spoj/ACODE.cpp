#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true)
	{
		string s;
		cin >> s;
		if(s == "0")
			break;
		vector<ll> dp(s.size() + 1, 1);
		if (s[1] == '0')
		{
			dp[1] = 1;
		}
		else if (s[0] == '0')
		{
			dp[1] = 0;
		}
		else if (s[0] == '1')
		{
			dp[1] = 2;
		}
		else if (s[0] > '2')
		{
			dp[1] = 1;
		}
		else if (s[1] <= '6')
		{
			dp[1] = 2;
		}
		else if (s[1] > '6')
		{
			dp[1] = 1;
		}
		for (ll i = 2; i < s.size(); i++)
		{
			if(s[i] == '0')
			{
				dp[i] = dp[i - 2];
			}
			else if (s[i - 1] == '0')
			{
				dp[i] = dp[i - 1];
			}
			else if (s[i - 1] == '1')
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			else if (s[i - 1] > '2')
			{
				dp[i] = dp[i - 1];
			}
			else if (s[i] <= '6')
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			else if (s[i] > '6')
			{
				dp[i] = dp[i - 1];
			}
		}
		cout << dp[s.size() - 1] << "\n";
	}
	return 0;
}
