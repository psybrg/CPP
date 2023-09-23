#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int i=0,a[26]={0};
    for(i=0;s[i]!='\0';i++)
    a[(int)s[i]-97]++;
    vector<int>v;
	for(i=0;i<26;i++)
        if(a[i]!=0)
            v.push_back(a[i]);
    sort(v.begin(),v.end());
    if(v[0]==1&&v[1]>1)
        v.erase(v.begin());
    else if(v[v.size()-1]>v[v.size()-2])
        v[v.size()-1]--;
    sort(v.begin(),v.end());
    for (i = 1; i < v.size(); i++)
        if(v[i]!=v[i-1])
            return "NO";
    return "YES";
}
int main()
{
    string s;
    getline(cin, s);
    string result = isValid(s);
    cout << result << "\n";
    return 0;
}
