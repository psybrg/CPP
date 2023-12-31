#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);

int luckBalance(int k, vector<vector<int>> contests)
{
    int i,n=contests.size(),t,s=0;
    vector<int>v;
    for(i=0;i<n;i++)
        if(contests[i][1]==1)
            v.push_back(contests[i][0]);
    sort(v.begin(),v.end());
    for(i=v.size()-1;i>=0&&k>0;i--,k--)
        s+=2*v[i];
    for(i=0;i<n;i++)
        if(contests[i][1]==0)
            s+=contests[i][0];
        else
            s-=contests[i][0];
    return s;
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);
    vector<string> nk = split_string(nk_temp);
    int n = stoi(nk[0]);
    int k = stoi(nk[1]);
    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++)
    {
        contests[i].resize(2);
        for (int j = 0; j < 2; j++)
            cin >> contests[i][j];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<luckBalance(k, contests)<<"\n";
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    vector<string> splits;
    char delimiter = ' ';
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    return splits;
}
