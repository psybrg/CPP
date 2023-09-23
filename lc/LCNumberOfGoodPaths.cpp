#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
class Solution {
    public:
    int findParent(vector<int> &parents, int i) {
        if (i == parents[i]) {
            return i;
        }
        return parents[i] = findParent(parents, parents[i]);
    }
    void makeUnion(vector<int> &parents, vector<int> &sizes, int a, int b) {
        a = findParent(parents, a);
        b = findParent(parents, b);
        if (a != b) {
            if (sizes[a] < sizes[b]) {
                swap(a, b);
            }
            parents[b] = a;
            sizes[a] += sizes[b];
        }
    }
    int numberOfGoodPaths(vector<int> &vals, vector<vector<int> > &edges) {
        vector<int> parents(vals.size());
        vector<int> sizes(vals.size(), 0);
        for (int i = 0; i < parents.size(); i++) {
            parents[i] = i;
        }
        map<int, vector<int> > val2Nodes;
        for (int i = 0; i < vals.size(); i++) {
            val2Nodes[vals[i]].push_back(i);
        }
        vector<vector<int> > graph(vals.size());
        for (int i = 0; i < edges.size(); i++) {
            if (vals[edges[i][0]] > vals[edges[i][1]]) {
                graph[edges[i][0]].push_back(edges[i][1]);
            } else {
                graph[edges[i][1]].push_back(edges[i][0]);
            }
        }
        int ans = vals.size();
        for (auto i = val2Nodes.begin(); i != val2Nodes.end(); i++) {
            for (int j = 0; j < i->second.size(); j++) {
                for (int k = 0; k < graph[i->second[j]].size(); k++) {
                    makeUnion(parents, sizes, i->second[j], graph[i->second[j]][k]);
                }
            }
            unordered_map<int, int> frequency;
            for (int j = 0; j < i->second.size(); j++) {
                frequency[findParent(parents, i->second[j])]++;
            }
            for (auto j = frequency.begin(); j != frequency.end(); j++) {
                ans += j->second * (j->second - 1) / 2;
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int> > nums(n - 1, vector<int>(2, 0));
    vector<int> vals(n);
    for (int i = 0; i < n; i++)
        cin >> vals[i];
    for (int i = 0; i < n - 1; i++)
        cin >> nums[i][0] >> nums[i][1];
    Solution solution;
    cout << solution.numberOfGoodPaths(vals, nums) << "\n";
    return 0;
}
