#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    // itoa
    void print(map<long long int, long long int> mp) {
        for (auto i = mp.begin(); i != mp.end(); i++) {
            cout << i->first << "\t" << i->second << "\n";
        }
        cout << "\n";
    }
    string intToString(long long int n) {
        if (n == 0) return "0";
        string s = "";
        bool sign = n > 0 ? false : true;
        n = n > 0 ? n : -n;
        while (n > 0) {
            string t = "0";
            t[0] += n % 10;
            s = t + s;
            n /= 10;
        }
        return sign ? "-" + s : s;
    }
    string fractionToDecimal(long long int n, long long int d) {
        if (n == 0) return "0";
        string ans = intToString(n / d);
        long long int rem = n % d;
        if (rem == 0) {
			if (n * d < 0) {
				return "-" + ans;
			}
			return ans;
		}
        ans += '.';
        map<long long int, long long int> rems;
        while (rem != 0) {
            if (rems.find(rem) != rems.end()) {
                string temp = ans.substr(0, rems[rem]);
                temp += '(';
                temp += ans.substr(rems[rem], ans.size() - rems[rem] + 1);
                temp += ')';
                cout << ans << "\n";
                ans = temp;
                break;
            } else {
                rems.insert(pair<long long int, long long int>(rem, ans.size()));
            }
            rem *= 10;
            ans += intToString(rem / d);
            rem = rem % d;
        }
        // print(rems);
        if (n * d < 0) {
            return "-" + ans;
        }
        return ans;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int a, d;
    cin >> a >> d;
    Solution solution;
    cout << solution.fractionToDecimal(a, d) << "\n";
    return 0;
}
