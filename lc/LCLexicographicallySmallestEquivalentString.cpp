#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    void print(vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            cout << char(v[i] + 'a') << " ";
        }
        cout << "\n";
    }
    int findParent(vector<int> &parent, int i) {
        if (parent[i] == i) {
            return parent[i];
        }
        return parent[i] = findParent(parent, parent[i]);
    }
    void makeUnion(vector<int> &parent, int a, int b) {
        int x = findParent(parent, a);
        int y = findParent(parent, b);
        if (x != y) {
            parent[x] = min(x, y);
            parent[y] = min(x, y);
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        for (int i = 0; i < s1.size(); i++) {
            makeUnion(parent, s1[i] - 'a', s2[i] - 'a');
        	print(parent);
        }
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = parent[parent[i]];
        }
        print(parent);
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) {
            ans += (char)('a' + parent[baseStr[i] - 'a']);
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b, c;
    cin >> a >> b >> c;
    Solution solution;
    cout << solution.smallestEquivalentString(a, b, c) << "\n";
    return 0;
}
