#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    vector<int> getOrder(vector<vector<int> > &tasks) {
        set<vector<long long int> > taskSet;
        for (long long int i = 0; i < tasks.size(); i++) {
            vector<long long int> v(3);
            v[0] = tasks[i][0];
            v[2] = i;
            v[1] = tasks[i][1];
            taskSet.insert(v);
        }
        set<vector<long long int> > availableTasks;
        auto adv = taskSet.begin();
        long long int clock = 1;
        vector<int> ans;
        while (adv != taskSet.end() || !availableTasks.empty()) {
            while (adv != taskSet.end() && clock >= (*adv)[0]) {
                vector<long long int> v(2);
                v[0] = (*adv)[1];
                v[1] = (*adv)[2];
                availableTasks.insert(v);
                adv++;
            }
            if (!availableTasks.empty()) {
                auto ptr = availableTasks.begin();
                clock += (*ptr)[0];
                ans.push_back((*ptr)[1]);
                availableTasks.erase(ptr);
            } else if (adv != taskSet.end()) {
                clock = max(clock, (*adv)[0]);
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int n, k;
    cin >> n >> k;
    vector<vector<int> > nums(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> nums[i][j];
    Solution solution;
    vector<int> ans = solution.getOrder(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << "\n";
    return 0;
}