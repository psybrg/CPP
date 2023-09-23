#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        set<pair<int, int> > tank;
        for (int i = 0; i < gas.size(); i++)
        {
            if(gas[i]>=cost[i]){
                tank.insert(pair<int,int>(gas[i]-cost[i], i));
            }
        }
        for (auto i = tank.rbegin(); i != tank.rend(); i++)
        {
            int fuel = 0;
            int start = i->second;
            for (int j = 0; j < gas.size(); j++) {
                fuel += gas[start];
                fuel -= cost[start];
                if(fuel<0){
                    break;
                }
                start = (start + 1) % gas.size();
            }
            if (start == i->second) return start;
        }
        return -1;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> gas(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++) cin >> gas[i];
    for (int i = 0; i < n; i++) cin >> cost[i];
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost) << "\n";
    return 0;
}
/*
f(i)=max(f(i-1), a[i]+f(i-2))
*/