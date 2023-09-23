#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int mag(int a) {
        return a > 0 ? a : -a;
    }
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> astros;
        for (int i = 0; i < asteroids.size(); i++) {
            if (!astros.empty() && astros.top() > 0 && asteroids[i] < 0) {
                bool astroidDestroyed = false;
                while (!astros.empty() && astros.top() > 0 && asteroids[i] < 0) {
                    if (mag(astros.top()) > mag(asteroids[i])) {
                        astroidDestroyed = true;
                        break;
                    } else if (mag(astros.top()) == mag(asteroids[i])) {
                        astroidDestroyed = true;
                        astros.pop();
                        break;
                    } else {
                        astros.pop();
                    }
                }
                if (!astroidDestroyed) {
                    astros.push(asteroids[i]);
                }
            } else {
                astros.push(asteroids[i]);
            }
        }
        vector<int> ans(astros.size());
        int idx = ans.size() - 1;
        while (!astros.empty()) {
            ans[idx--] = astros.top();
            astros.pop();
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r;
    cin >> r;
    vector<int> nums(r);
    for (int i = 0; i < r; i++)
        cin >> nums[i];
    Solution solution;
    vector<int> ans = solution.asteroidCollision(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\t";
    }
    cout << "\n";
    return 0;
}
