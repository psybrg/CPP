#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    bool isInvalidString(string s) {
        // cout<<s<<"\n";
        vector<int> v(10, 0);
        for (int l = 0; l < s.size(); l++) {
            v[s[l] - '0']++;
            if (v[s[l] - '0'] > 1) return true;
        }
        return false;
    }
    bool isValidSudoku(vector<string>& board) {
        int n = sqrt(board.size());
        for (int i = 0; i < board.size(); i++) {
            string s = "";
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] >= '0' && board[i][j] <= '9') s += board[i][j];
            }
            if (isInvalidString(s)) return false;
        }
        for (int i = 0; i < board.size(); i++) {
            string s = "";
            for (int j = 0; j < board[i].size(); j++) {
                if (board[j][i] >= '0' && board[j][i] <= '9') s += board[j][i];
            }
            if (isInvalidString(s)) return false;
        }
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                string s = "";
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (board[i + k][j + l] >= '0' &&
                            board[i + k][j + l] <= '9')
                            s += board[i + k][j + l];
                    }
                }
                if (isInvalidString(s)) return false;
            }
        }
        return true;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> board(n);
    string word;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    Solution solution;
    cout << solution.isValidSudoku(board) << "\n";
    return 0;
}