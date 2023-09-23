#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int strStr(string haystack, string needle) {
        auto i = haystack.find(needle);
        if (i != string::npos) {
            return i;
        }
        return -1;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    Solution solution;
    cout << solution.strStr(a, b) << "\n";
    return 0;
}