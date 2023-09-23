#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
    int getLiveNeighbours(int r, int c, vector<vector<int> > &matrix){
        int live = 0;
        for (int i = -1; i < 2; i++){
            for (int j = -1; j < 2; j++){
                if((r + i) >= 0 && (r + i) < matrix.size() && (c + j) >= 0 && (c + j) < matrix[r].size() && matrix[r + i][c + j] == 1 && (i != 0 || j != 0)){
                    live++;
                }
            }
        }
        return live;
    }
    void gameOfLife(vector<vector<int> > &matrix){
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> v(r, 0);
        for (int i = 0; i < r; i++)
        {
            int p = 1;
            for (int j = 0; j < c; j++, p *= 2)
            {
                if (matrix[i][j] == 1)
                {
                        v[i] = v[i] | p;
                }
            }
        }
        for (int i = 0; i < r; i++){
            int p = 1;
            for (int j = 0; j < c; j++, p*=2){
                int l = getLiveNeighbours(i, j, matrix);
                if (matrix[i][j] == 1){
                    if(l < 2 || l > 3){
                        int q = -1 ^ p;
                        v[i] = v[i] & q;
                    }
                }
                else if(l == 3){
                    v[i] = v[i] | p;
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            int p = 1;
            for (int j = 0; j < c; j++, p *= 2)
            {
                if (v[i] & p){
                    matrix[i][j] = 1;
                }
                else{
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c;
    cin >> r >> c;
    Solution solution;
    vector<vector<int> > matrix(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
        solution.gameOfLife(matrix);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
