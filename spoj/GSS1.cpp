#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll sum;
	ll left;
	ll right;
	ll best;
	ll pfxSum;
	ll sfxSum;
};
ll minimumNum;
ll max(ll a, ll b)
{
	return a > b ? a : b;
}
ll queryMaxSum(vector<node>&V, ll i, ll lo, ll hi) {
	if(lo <= V[i].left && hi >= V[i].right)
		return V[i].best;
	if(lo > V[i].right || hi < V[i].left)
		return minimumNum;
	ll m0 = queryMaxSum(V, (i * 2 + 1) > (V.size() - 1) ? (V.size() - 1) : (i * 2 + 1), lo, hi);
	ll m1 = queryMaxSum(V, (i * 2 + 2) > (V.size() - 1) ? (V.size() - 1) : (i * 2 + 2), lo, hi);
	return max(max(m0, m1), m0 + m1);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n;
	cin >> n;
	vector<node> v(2 * n - 1);
	if(n < 2){
		cin >> v[0].sum;
		v[0].left = 0;
		v[0].right = 0;
		v[0].best = v[0].sum;
		v[0].pfxSum = v[0].sum;
		v[0].sfxSum = v[0].sum;
		minimumNum = v[0].sum;
	}
	else for (ll j = 0, i = n - 1 + (n % 2); j < n; j++){
		cin >> v[i].sum;
		v[i].left = j;
		v[i].right = j;
		v[i].best = v[i].sum;
		v[i].pfxSum = v[i].sum;
		v[i].sfxSum = v[i].sum;
		if(minimumNum > v[i].sum)
			minimumNum = v[i].sum;
		i++;
		if (i >= v.size())
			i = i - n;
	}
	for (ll i = 2 * n - 3; i > 0; i-=2){
		v[(i - 1) / 2].left = v[i].left < v[i + 1].left ? v[i].left : v[i + 1].left;
		v[(i - 1) / 2].right = v[i].right > v[i + 1].right ? v[i].right : v[i + 1].right;
		v[(i - 1) / 2].pfxSum = max(v[i].pfxSum, v[i].sum + v[i + 1].pfxSum);
		v[(i - 1) / 2].sfxSum = max(v[i + 1].sfxSum, v[i].sfxSum + v[i + 1].sum);
		v[(i - 1) / 2].sum = v[i].sum + v[i + 1].sum;
		v[(i - 1) / 2].best = max(max(v[(i - 1) / 2].sum, max(v[(i - 1) / 2].pfxSum, v[(i - 1) / 2].sfxSum)), max(max(v[i].best, v[i + 1].best), v[i].sfxSum + v[i + 1].pfxSum));
	}
	ll q;
	cin >> q;
	minimumNum--;
	for (ll i = 0; i < v.size(); i++){
		
	}
	
	while (q--)
	{
		ll lo, hi;
		cin >> lo >> hi;
		cout << queryMaxSum(v, 0, lo - 1, hi - 1) << "\n";
	}
	return 0;
}
