#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    void printMap(map<int, int> &nums) {
        for (auto i = nums.begin(); i != nums.end(); i++) {
            cout << i->first << " -> " << i->second << "\n";
        }
        cout << "\n";
    }
    int numBusesToDestination(vector<vector<int> > &routes, int src, int dst) {
        queue<int> Q;
        vector<int> distance(1000001, -1);
        map<int, vector<int> > routesToBus;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                routesToBus[routes[i][j]].push_back(i);
            }
        }
        Q.push(src);
		distance[src] = 0;
        // cout << '\n';
        // printMap(distance);
        while (!Q.empty()) {
            int city = Q.front();
            Q.pop();
            // cout << "city : " << city << "\n";
            for (int i = 0; i < routesToBus[city].size(); i++) {
                for (int j = 0; j < routes[routesToBus[city][i]].size(); j++) {
                    if (distance[routes[routesToBus[city][i]][j]] < 0) {
                        distance[routes[routesToBus[city][i]][j]] = 1 + distance[city];
                        Q.push(routes[routesToBus[city][i]][j]);
                    }
                    if (dst == routes[routesToBus[city][i]][j]) {
                        // printMap(distance);
                        return distance[dst];
                    }
                }
            }
        }
        // printMap(distance);
        return -1;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s, m, n, d;
    cin >> m >> n;
    vector<vector<int> > routes(m ,vector<int>(n, 0));
    for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
            cin >> routes[i][j];
        }
    }
    cout << "Enter SRC & DST : ";
    cin >> s >> d;
    Solution solution;
    cout << solution.numBusesToDestination(routes, s, d) << "\n";
    return 0;
}
int main1(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int> > routes;
    int s, t, d;
    cin >> t;
    while (t > 0) {
        vector<int> tmp(t);
        for (int i = 0; i < t; i++) {
            cin >> tmp[i];
        }
        routes.push_back(tmp);
        cin >> t;
    }
    cin >> s >> d;
    Solution solution;
    cout << solution.numBusesToDestination(routes, s, d) << "\n";
    return 0;
}
/*

3
1 2 7
3
3 6 7
0
1 6

*/