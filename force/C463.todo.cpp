#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n, 0));
	vector<ll>diagonals0(2 * n  - 1, 0);
	vector<ll>diagonals1(2 * n  - 1, 0);
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			cin >> grid[i][j];
			diagonals0[i + j] += grid[i][j];
			diagonals1[(i + j + n - 1) % (2 * n - 1)] += grid[i][j];
		}
	}
	ll mx0 = INT_MIN, mx1 = INT_MIN, x0, x1, y0, y1;
	for (int i = 0; i < diagonals0.size(); i++)
	{
		for (int j = i + (n + 1) % 2; j < diagonals1.size(); j+=2)
		{
			ll d = j - n + 1;
			ll x = (i + d) / 2;
			x = (x + n * n) % n;
			ll y = (i - d) / 2;
			y = (y + n * n) % n;
			if(i % 2 == 0 && mx0 < diagonals0[i] + diagonals1[j] - grid[x][y]) {
				mx0 = diagonals0[i] + diagonals1[j] - grid[x][y];			
				x0 = x;
				y0 = y;
				cout << x << "\t" << y << "\t" << i << "\t" << j << "\n";
			}
			if(i % 2 == 1 && mx1 < diagonals0[i] + diagonals1[j] - grid[x][y]) {
				mx1 = diagonals0[i] + diagonals1[j] - grid[x][y];			
				x1 = x;
				y1 = y;
			}
		}
	}
	cout << mx0 + mx1 << "\n" << x0 + 1 << " " << y0 + 1 << " " << x1 + 1 << " " << y1 + 1 << "\n";
	return 0;
}