#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    void DFS(vector<vector<int> > &graph, vector<bool> &visited,
             vector<int> &toposort, int vertex) {
        visited[vertex] = true;
        for (int i = 0; i < graph[vertex].size(); i++) {
            if (!visited[graph[vertex][i]]) {
                DFS(graph, visited, toposort, graph[vertex][i]);
            }
        }
        toposort.push_back(vertex);
    }
    bool canFinish(int numCourses, vector<vector<int> > &prerequisites) {
        vector<int> toposort;
        vector<vector<int> > graph(numCourses);
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            if (prerequisites[i][0] == prerequisites[i][1]) return false;
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                DFS(graph, visited, toposort, i);
            }
        }
        map<int, int> cache;
        for (int i = 0; i < toposort.size(); i++) {
            cache.insert(pair<int, int>(toposort[i], i));
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            if (cache[prerequisites[i][0]] < cache[prerequisites[i][1]]) {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > nums(k, vector<int>(2, 0));
    for (int i = 0; i < k; i++) cin >> nums[i][0] >> nums[i][1];
    Solution solution;
    bool ans = solution.canFinish(n, nums);
    cout << ans << "\n";
    return 0;
}
