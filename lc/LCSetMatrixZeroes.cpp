#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    void makeCol0(int c, vector<vector<int> >& matrix){
        for(int i=0;i<matrix.size();i++)
            matrix[i][c]=0;
    }
    void makeRow0(int r, vector<vector<int> >& matrix){
        for(int i=0;i<matrix[r].size();i++)
            matrix[r][i]=0;
    }
    void setZeroes(vector<vector<int> >& matrix){
        vector<int>rows(matrix.size(),1);
        vector<int>cols(matrix[0].size(),1);
        for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    rows[i]=0;
                    cols[j]=0;
                }
			}
		}
		for(int i=0;i<rows.size();i++)
            if(rows[i]==0)
                makeRow0(i, matrix);
        for(int i=0;i<cols.size();i++)
            if(cols[i]==0)
                makeCol0(i, matrix);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<vector<int> > matrix(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> matrix[i][j];
    Solution solution;
    solution.setZeroes(matrix);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
	}
	return 0;
}
