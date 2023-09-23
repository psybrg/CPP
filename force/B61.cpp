#include<bits/stdc++.h>
using namespace std;

string purify(string input)
{
    string result = "";
    for (int i = 0; i < input.size(); i++)
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
            result += input[i];
    return result;
}
bool caseInsensitiveCompare(const string a, const string b)
{
    if(a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] == b[i] || a[i]-b[i]-'A'+'a' == 0 || a[i]-b[i]-'a'+'A' == 0)
            continue;
        else
            return false;
    }
    return true;
}
string checkResponse(const vector<string>&combos, string response)
{
    for (size_t i = 0; i < combos.size(); i++)
        if(caseInsensitiveCompare(combos[i],response))
            return "ACC";
    return "WA";
}
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    vector<string>inputs(3);
    inputs[0] = purify(a);
    inputs[1] = purify(b);
    inputs[2] = purify(c);
    vector<string>combos(6);
    combos[0] = inputs[0]+inputs[1]+inputs[2];
    combos[1] = inputs[0]+inputs[2]+inputs[1];
    combos[2] = inputs[1]+inputs[0]+inputs[2];
    combos[3] = inputs[1]+inputs[2]+inputs[0];
    combos[4] = inputs[2]+inputs[0]+inputs[1];
    combos[5] = inputs[2]+inputs[1]+inputs[0];
    int n;
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        cout<<checkResponse(combos, purify(s))<<endl;
    }
    return 0;
}
