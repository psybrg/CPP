#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
    return (a > b) ? b : a;
}
int countSubstrings(string s) {
    int n = s.size(), r = 0, c = 0, ans = 0;
    vector<char> S(2 * n + 3, '#');
    vector<int> P(2 * n + 3, 0);
    S[0] = '!';
    s[2 * n + 2] = '@';
    for (int i = 0; i < n; i++)
        S[2 * i + 2] = s[i];
    for (int i = 1; i < (2 * n + 2); i++) {
        if (i < r && 2 * c >= i)
            P[i] = min(r - i, P[2 * c - i]);
        if ((i + 1 + P[i]) < S.size() && (i - 1 - P[i]) >= 0)
            while (S[i + (1 + P[i])] == S[i - (1 + P[i])])
                P[i]++;
        if (r < (i + P[i])) {
            r = i + P[i];
            c = i;
        }
    }
    for (int i = 0; i < P.size(); i++)
        ans += (P[i] + 1) / 2;
    return ans - s.size();
}
int main() {
    string s;
    cin >> s;
    cout << countSubstrings(s);
    return 0;
}