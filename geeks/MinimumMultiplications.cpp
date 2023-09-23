#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        queue<int> q;
        vector<int> dist(100001, -1);
        int mod = 100000;
        dist[start % mod] = 0;
        q.push(start % mod);
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if (end == num) {
                return dist[num];
            }
            for (int i = 0; i < arr.size(); i++) {
                int x = ((num % mod) * (arr[i] % mod)) % mod;
                if (dist[x] < 0) {
                    q.push(x);
                    dist[x] = 1 + dist[num];
                }
            }
        }
        return -1;
    }
    void print(vector<int> &rems) {
        for (int i = 0; i < rems.size(); i++) {
            cout << rems[i] << "\t";
        }
        cout << "\n";
    }
};

// HARD

int main(int argc, char const *argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, n;
        cin >> n >> a >> b;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution sol;
        cout << sol.minimumMultiplications(arr, a, b);
    }
    return 0;
}

/*
f[i, a, b] = f[i, a * v[i], b] || f[i + 1, a, b]
*/