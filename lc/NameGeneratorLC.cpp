#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    string t = "LC";
    bool capitalise = true;
    for (int i = 0; i < s.size(); i++) {
        if (capitalise && s[i] >= 'a' && s[i] <= 'z') {
            t += s[i] + 'A' - 'a';
            capitalise = false;
        } else if ((s[i] >= 'a' && s[i] <= 'z') ||
                   (s[i] >= 'A' && s[i] <= 'Z') ||
                   (s[i] >= '0' && s[i] <= '9')) {
            t += s[i];
        } else {
            capitalise = true;
        }
    }
    cout << "\n" << t << "\n\n";
}
