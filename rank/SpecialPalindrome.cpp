#include<bits/stdc++.h>
using namespace std;
long substrCount(int n, string s)
{
    int i,t=1;
    long ans=0;
    vector<int>v;
    vector<char>ch;
    for(i=0;i<n;i++)
    {
        if(s[i]==s[i+1])
            t++;
        else
        {
            ans+=t*(t+1)/2;
            v.push_back(t);
            ch.push_back(s[i]);
            t=1;
        }
    }
    for(i=1;i<v.size()-1;i++)
        if(v[i]==1)
            if(ch[i-1]==ch[i+1])
            {
                int min=(v[i+1]<v[i-1])?v[i+1]:v[i-1];
                ans+=min/*(min+1)/2/**/;
            }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    getline(cin, s);
    //cout<<"hey"<<endl;
    long result = substrCount(n, s);
    cout << result << "\n";
    return 0;
}
