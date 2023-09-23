#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int getSum(int a, int b) {
        int i = 1;
        int s = 0;
        bool c = false;
        while (i > 0) 
        // while (i != -1 && i != 0) 
        {
            bool x = i & a;
            bool y = i & b;
            cout << i << "\n";
            if (c) {
                if (x) {
                    if (y) {
                        s = i | s;
                        c = true;
                    } else {
                        c = true;
                    }
                } else {
                    if (y) {
                        c = true;
                    } else {
                        s = i | s;
                        c = false;
                    }
                }
            } else {
                if (x) {
                    if (y) {
                        c = true;
                    } else {
                        s = i | s;
                        c = false;
                    }
                } else {
                    if (y) {
                        s = i | s;
                        c = false;
                    } else {
                        c = false;
                    }
                }
            }
            i = i << 1;
        }
        return s;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    Solution solution;
    cout << solution.getSum(a, b) << "\n";
    return 0;
}
