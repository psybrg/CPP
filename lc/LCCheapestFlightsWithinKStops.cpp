#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    void print(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << "\n";
    }
    int findCheapestPrice(int n, vector<vector<int> > &flights, int src, int dst, int k) {
        if (k < 0) {
            return -1;
        }
        k++;
        vector<vector<vector<int> > > graph(n);
        for (int i = 0; i < flights.size(); i++) {
            vector<int> temp(2);
            temp[0] = flights[i][1];
            temp[1] = flights[i][2];
            graph[flights[i][0]].push_back(temp);
        }
        queue<pair<int, int> > Q;
        vector<int> costs(n, -1);
        costs[src] = 0;
        Q.push(pair<int, int>(src, 0));
        while (!Q.empty() && k > 0) {
            int numOfNodesToBePopped = Q.size();
            while (numOfNodesToBePopped--) {
                pair<int, int> nodeAndCost = Q.front();
                int node = nodeAndCost.first;
                int cost = nodeAndCost.second;
                Q.pop();
                for (int i = 0; i < graph[node].size(); i++) {
                    if (costs[graph[node][i][0]] < 0 || costs[graph[node][i][0]] > cost + graph[node][i][1]) {
                        costs[graph[node][i][0]] = cost + graph[node][i][1];
                        Q.push(pair<int, int>(graph[node][i][0], cost + graph[node][i][1]));
                    }
                }
            }
            print(costs);
            k--;
        }
        return costs[dst];
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << "#Nodes, #Edges, Stops, SRC, DST\n";
    int n, m, a, b, k;
    cin >> n >> m >> k >> a >> b;
    vector<vector<int> > nums(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++)
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    Solution solution;
    cout << solution.findCheapestPrice(n, nums, a, b, k) << "\n";
    return 0;
}
