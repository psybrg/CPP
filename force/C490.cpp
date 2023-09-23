#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	string s;
	int a, b;
	cin >> s >> a >> b;
	set<int> flag;
	int num = 0, x = 1, c = 0;
	for (int i = 0; i < s.size(); i++) {
		num = 10 * num + int(s[i] - '0');
		num = num % a;
		if (num == 0) {
			flag.insert(i);
		}
		if (s[i] == '0' && flag.find(i - 1) != flag.end()) {
			flag.erase(i - 1);
		}
	}
	num = 0;
	for (int i = s.size() - 1; i > 0; i--) {
		num = num + x*(s[i] - '0');
		num = num % b;
		x = (x * 10) % b;
		if(flag.find(i - 1) != flag.end() && num == 0) {
			cout << "YES\n" << s.substr(0, i) << "\n" << s.substr(i, s.size() - i + 1) << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}