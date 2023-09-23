#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll value;
	ll left;
	ll right;
};
ll queryMaxValue(vector<node>&V, ll i, ll lo, ll hi) {
	if(lo <= V[i].left && hi >= V[i].right)
		return V[i].value;
	if(lo > V[i].right || hi < V[i].left)
		return INT64_MIN;
	ll m0 = queryMaxValue(V, (i * 2 + 1) > (V.size() - 1) ? (V.size() - 1) : (i * 2 + 1), lo, hi);
	ll m1 = queryMaxValue(V, (i * 2 + 2) > (V.size() - 1) ? (V.size() - 1) : (i * 2 + 2), lo, hi);
	return m0 > m1 ? m0 : m1;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<node> v(2 * n - 1);
	for (ll j = 0, i = n - 1 + (n % 2); j < n; j++){
		cin >> v[i].value;
		v[i].left = j;
		v[i].right = j;
		i++;
		if (i >= v.size())
			i = i - n;
	}
	for (ll i = 2 * n - 3; i > 0; i-=2){
		v[(i - 1) / 2].value = v[i].value > v[i + 1].value ? v[i].value : v[i + 1].value;
		v[(i - 1) / 2].left = v[i].left < v[i + 1].left ? v[i].left : v[i + 1].left;
		v[(i - 1) / 2].right = v[i].right > v[i + 1].right ? v[i].right : v[i + 1].right;
	}
	// for (ll i = 0; i < v.size(); i++){
		// printf("%lld : %lld -> %lld\n", v[i].value, v[i].left, v[i].right);
	// }
	ll q;
	cin >> q;
	while (q--) {
		ll lo, hi;
		cin >> lo >> hi;
		cout << queryMaxValue(v, 0, lo - 1, hi - 1) << "\n";
	}
	return 0;
}
