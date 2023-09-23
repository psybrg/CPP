#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    vector<vector<int> > moves;
    bool isValidMove(int i, int j, vector<string>& board) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
    }
    bool search(vector<string>& board, vector<vector<bool> >& visited, string& word, int i, int j, int x) {
        cout << i << "\t" << j << "\t" << word[x] << "\n";
        if (x == word.size() - 1) {
            return isValidMove(i, j, board) && word[x] == board[i][j];
        }
        if (x < word.size() && isValidMove(i, j, board) && word[x] == board[i][j]) {
            visited[i][j] = true;
            bool temp = false;
            for (int k = 0; k < moves.size(); k++) {
                int r = i + moves[k][0], c = j + moves[k][1];
                if (isValidMove(r, c, board) && !visited[r][c] &&
                    word[x + 1] == board[r][c]) {
                    temp = temp | search(board, visited, word, r, c, x + 1);
                }
            }
            visited[i][j] = false;
            return temp;
        }
        return false;
    }
    bool exist(vector<string>& board, string word) {
        moves = vector<vector<int> >(4, vector<int>(2, 0));
        moves[0][1] = 1;
        moves[1][1] = -1;
        moves[2][0] = 1;
        moves[3][0] = -1;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool> > visited(
                        board.size(), vector<bool>(board[0].size(), false));
                    if (search(board, visited, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
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
    cin >> word;
    Solution solution;
    cout << solution.exist(board, word) << "\n";
    return 0;
}