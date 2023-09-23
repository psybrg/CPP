#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    public:
    char nonrepeatingCharacter(string S) {
        vector<int> hash(260, 0);
        vector<char> chars;
        for (int i = 0; i < S.size(); i++) {
            hash[S[i]]++;
            if (hash[S[i]] == 1) {
                chars.push_back(S[i]);
            } else {
                for (int j = 0; j < chars.size(); j++) {
                    if (chars[j] == S[i]) {
                        chars[j] = '$';
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < chars.size(); i++) {
            if ((chars[i] >= 'a' && chars[i] <= 'z') || (chars[i] >= 'A' && chars[i] <= 'Z')) {
                return chars[i];
            }
        }
        return '$';
    }
};

int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string k;
        cin >> k;
        Solution sol;
        cout << sol.nonrepeatingCharacter(k) << "\n";
    }
    return 0;
}