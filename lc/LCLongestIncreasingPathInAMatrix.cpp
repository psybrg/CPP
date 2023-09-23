#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
    public:
    int isValid(vector<vector<int> > &matrix, int r, int c) {
        return r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size();
    }
    vector<vector<int> > drxn = vector<vector<int> >(4, vector<int>(2, 0));
    int longestIncreasingPath(vector<vector<int> > &matrix, int r, int c, vector<vector<int> > &visited) {
        visited[r][c] = 1;
        int dist = 0;
        for (int i = 0; i < 4; i++) {
            if (isValid(matrix, r + drxn[i][0], c + drxn[i][1])) {
                if (matrix[r][c] > matrix[r + drxn[i][0]][c + drxn[i][1]]) {
                    if (visited[r + drxn[i][0]][c + drxn[i][1]] == 0) {
                        dist = max(dist, longestIncreasingPath(matrix, r + drxn[i][0], c + drxn[i][1], visited));
                    } else {
                        dist = max(dist, visited[r + drxn[i][0]][c + drxn[i][1]]);
                    }
                }
            }
        }
        return visited[r][c] = 1 + dist;
    }
    int longestIncreasingPath(vector<vector<int> > &matrix) {
        drxn[0][0] = 1;
        drxn[1][0] = -1;
        drxn[2][1] = 1;
        drxn[3][1] = -1;
        int ans = 1;
        vector<vector<int> > visited(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                // cout << i << ", " << j << "\t";
                ans = max(longestIncreasingPath(matrix, i, j, visited), ans);
                // cout << ans << "\n";
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int r, c;
    cin >> r >> c;
    Solution solution;
    vector<vector<int> > matrix(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << solution.longestIncreasingPath(matrix) << "\n";
    return 0;
}
/*

15	10

0	1	2	3	4	5	6	7	8	9
19	18	17	16	15	14	13	12	11	10
20	21	22	23	24	25	26	27	28	29
39	38	37	36	35	34	33	32	31	30
40	41	42	43	44	45	46	47	48	49
59	58	57	56	55	54	53	52	51	50
60	61	62	63	64	65	66	67	68	69
79	78	77	76	75	74	73	72	71	70
80	81	82	83	84	85	86	87	88	89
99	98	97	96	95	94	93	92	91	90
100	101	102	103	104	105	106	107	108	109
119	118	117	116	115	114	113	112	111	110
120	121	122	123	124	125	126	127	128	129
139	138	137	136	135	134	133	132	131	130
0	0	0	0	0	0	0	0	0	0

*/

/*

3	3

7	8	9
9	7	6
7	2	3

*/