#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution{
public:
    void rotate(vector<vector<int> > &matrix){
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i; j < n - 1 - i; j++)
            {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
int main(int argc, char const *argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Solution solution;
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
        solution.rotate(matrix);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
