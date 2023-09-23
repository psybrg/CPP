#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<string>split(string s,char c)
{
    vector<string>vs;
    for(int i = 0,lo=0; i < s.size(); i++)
    {
        if(s[i]==c)
        {
            vs.push_back(s.substr(lo,i-lo));
            lo=i+1;
        }
    }
    return vs;
}
void goPro(map<string,int>&m,string s,int x)
{
    auto i=m.find(s);
    if(i==m.end())
        m.insert({s,x});
    else
        i->second+=x;
}
int main(int argc, char const *argv[])
{
    string name,z;
    cin>>name;
    int t;
    cin>>t;
    map<string,int>m;
    getline(cin,z);
    while(t--)
    {
        string s;
        getline(cin,s);
        vector<string>vs=split(s,' ');
        string x=vs[0];
        string y=vs[vs.size()-1].substr(0,vs[vs.size()-1].size()-2);
        int z;
        if(vs[1]=="posted")
            z=15;
        else if(vs[1]=="commented")
            z=10;
        else
            z=5;
        if(name==x)
            goPro(m,y,z);
        else if(name==y)
            goPro(m,x,z);
        goPro(m,x,0);
        goPro(m,y,0);
    }
    m.erase(name);
    multimap<int,string,greater<int>>R;
    for (auto i=m.begin(); i!=m.end(); i++)
        R.insert({i->second,i->first});
    for (auto i=R.begin(); i!=R.end(); i++)
        cout<<i->second<<endl;
    return 0;
}
