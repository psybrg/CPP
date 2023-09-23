#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    vector<int> dfs(vector<vector<int> > &adjList, vector<int> &ans, int node, string &labels) {
        vector<int> freq(26, 0);
        for (int i = 0; i < adjList[node].size(); i++) {
            vector<int> tmp = dfs(adjList, ans, adjList[node][i], labels);
            for (int j = 0; j < tmp.size(); j++) {
                freq[j] += tmp[j];
            }
        }
        freq[labels[node] - 'a']++;
        ans[node] = freq[labels[node] - 'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int> > &edges, string labels) {
        vector<int> ans(n, 1);
        vector<vector<int> > adjList(n);
        set<int> cache;
        cache.insert(0);
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] != edges[i][1]) {
                if (cache.find(edges[i][0]) != cache.end()) {
                    adjList[edges[i][0]].push_back(edges[i][1]);
                    cache.insert(edges[i][1]);
                } else {
                    adjList[edges[i][1]].push_back(edges[i][0]);
                    cache.insert(edges[i][0]);
                }
            }
        }
        dfs(adjList, ans, 0, labels);
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int> > edges(n - 1, vector<int>(2));
    for (int i = 0; i < edges.size(); i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    Solution solution;
    vector<int> ans = solution.countSubTrees(n, edges, s);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
