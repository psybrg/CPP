#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frq(26, 0);
        int maxFrq = 0;
        int maxFrqFrq = 0;
        for (int i = 0; i < tasks.size(); i++) {
            frq[tasks[i] - 'A']++;
            if (maxFrq < frq[tasks[i] - 'A']) {
                maxFrq = frq[tasks[i] - 'A'];
                maxFrqFrq = 1;
            }
            else if (maxFrq == frq[tasks[i] - 'A']) {
                maxFrqFrq++;
            }
        }
        return (int)tasks.size() + max(0, (maxFrq - 1) * (n + 1 - maxFrqFrq) - (int)tasks.size() + maxFrq * maxFrqFrq);
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<char> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.leastInterval(nums, k) << "\n";
    return 0;
}

/*

52 2
AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ

27 29
AABCDEFGHIJKLMNOPQRSTUVWXYZ

12 2
AAABBBCCCDDE

6 50
AAABBB

6 2
AAABBB

6 0
AAABBB

12 2
AAAAAABCDEFG

*/