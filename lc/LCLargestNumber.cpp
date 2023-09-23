#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    static bool comparator(int a, int b) {
        string c = intToString(a);
        string d = intToString(b);
        string e = c + d;
        string f = d + c;
        return e > f;
    }
    static string intToString(int n) {
        string s = "";
        if (n == 0) return "0";
        bool sign = n > 0 ? false : true;
        n = n > 0 ? n : -n;
        while (n > 0) {
            s = (char)('0' + n % 10) + s;
            n /= 10;
        }
        return sign ? "-" + s : s;
    }
    static bool allZero(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) return false;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        if (allZero(nums)) return "0";
        string s = "";
        vector<string> vs(nums.size());
        sort(nums.begin(), nums.end(), comparator);
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << "\n";
            s += intToString(nums[i]);
        }
        cout << "\n";
        return s;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << "sizeof(int) = " << sizeof(int) << "\n";
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    Solution solution;
    cout << solution.largestNumber(nums) << "\n";
    return 0;
}