#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    vector<string> rec (int a, int b, int balance){
        if(a < 1 && b > 0){
            string s = "";
            for (int i = 0; i < b; i++){
                s += ")";
            }
            return vector<string>(1, s);
        }
        if (b < 1 && a > 0){
            string s = "";
            for (int i = 0; i < a; i++){
                s += "(";
            }
            return vector<string>(1, s);
        }
        vector<string> vs;
        if (a > 0 && b > 0)
        {
            if(balance >= 0){
                vector<string> temp0 = rec(a - 1, b, balance + 1);
                for (int i = 0; i < temp0.size(); i++){
                    vs.push_back("(" + temp0[i]);
                }
            }
            if(balance > 0){
                vector<string> temp1 = rec(a, b - 1, balance - 1);
                for (int i = 0; i < temp1.size(); i++){
                    vs.push_back(")" + temp1[i]);
                }
            }
        }
        return vs;
    }
    vector<string> generateParenthesis(int n)
    {
        return rec(n, n, 0);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Solution solution;
    vector<string> ans = solution.generateParenthesis(n);
    for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << "\n";
	}
	return 0;
}
