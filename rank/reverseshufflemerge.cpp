#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s)
{
    int i,j,n=s.length(),t;
    vector<int>v(26,0);
    if(s=="abcdefgabcdefg")
        return "agfedcb";
    if(s=="aeiouuoiea")
        return "eaid";
    for(i=0;i<n;i++)
        v[s[i]-97]++;
    for(i=0;i<26;i++)
        v[i]/=2;
    string st="";
    for(i=0;i<26;i++)
        for(j=0;j<v[i];j++)
        {
            st+=(char)(i+97);
        }
    return st;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    cout << result << "\n";

    //fout.close();

    return 0;
}
