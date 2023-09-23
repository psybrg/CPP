#include <bits/stdc++.h>
#include <map>
#include <set>
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
        if (src == dst)
            return 0;
        int distance = 1;
        queue<int> Q;
        unordered_set<int> visited;
        unordered_map<int, unordered_set<int> > routesToBus;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                routesToBus[routes[i][j]].insert(i);
            }
        }
        for (auto i = routesToBus[src].begin(); i != routesToBus[src].end(); i++) {
            Q.push(*i);
            visited.insert(*i);
        }
        while (Q.size()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                int bus = Q.front();
                Q.pop();
                int start = -1;
                for (int j = 0; j < routes[bus].size(); j++) {
                    if (start == -1) {
                        start = routes[bus][j];
                    } else if (start == routes[bus][j]) {
                        break;
                    }
                    if (routes[bus][j] == dst)
                        return distance;
                    for (auto k = routesToBus[routes[bus][j]].begin(); k != routesToBus[routes[bus][j]].end(); k++) {
                        if (!visited.count(*k)) {
                            visited.insert(*k);
                            Q.push(*k);
                        }
                    }
                }
            }
            distance++;
        }
        return -1;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s, m, n, d;
    cin >> m >> n;
    vector<vector<int> > routes(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
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