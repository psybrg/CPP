#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    bool equalHash(vector<int> &h1, vector<int> &h2) {
        if (h1.size() != h2.size()) {
            return false;
        }
        for (int i = 0; i < h1.size() && i < h2.size(); i++) {
            if (h1[i] != h2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> h1(26, 0);
        vector<int> h2(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            h1[s1[i] - 'a']++;
            h2[s2[i] - 'a']++;
        }
		for (int i = s1.size(); i < s2.size(); i++)
		{
			if(equalHash(h1, h2)) {
                return true;
            }
            h2[s2[i] - 'a']++;
            h2[s2[i - s1.size()] - 'a']--;
        }
        return equalHash(h1, h2);
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, k;
    cin >> s >> k;
    Solution solution;
    cout << solution.checkInclusion(s, k) << "\n";
    return 0;
}