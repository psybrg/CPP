#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int islands = 0;
    map<int, int> parent;
    int find(int x) {
        if (!parent.count(x)) {
            parent[x] = x;
            islands++;
        }
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    };
    void setUnion(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
	        islands--;
        }
    };
    int removeStones(vector<vector<int> > &stones) {
        for (int i = 0; i < stones.size(); ++i)
            setUnion(stones[i][0], ~stones[i][1]);
        return stones.size() - islands;
    };
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int> > nums(n, vector<int>(2, 0));
    for (int j = 0; j < n; j++)
        cin >> nums[j][0] >> nums[j][1];
    Solution solution;
    cout << solution.removeStones(nums) << "\n";
    return 0;
}