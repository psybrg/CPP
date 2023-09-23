#include<bits/stdc++.h>
using namespace std;
struct Student{
	int mat;
	int eng;
	int sci;
	int ssc;
	int total;
};
int main() {
    int n;
    cin >> n;
    vector<Student> vs;
    int maxMat = 0, maxEng = 0, maxSci = 0, maxSsc = 0, max = 0;
    for (int i = 0; i < n; i++) {
        int m, e, c, s, t;
        cin >> m >> e >> c >> s;
        Student st;
        st.mat = m;
        st.eng = e;
        st.sci = c;
        st.ssc = s;
        st.total = t = m + e + c + s;
        maxMat = maxMat > m ? maxMat : m;
        maxEng = maxEng > e ? maxEng : e;
        maxSci = maxSci > c ? maxSci : c;
        maxSsc = maxSsc > s ? maxSsc : s;
        max = max > t ? max : t;
    }
    cout << maxMat << "\t" << maxEng << "\t" << maxSci << "\t" << maxSsc << "\t" << max << "\n";
    return 0;
}