#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    map<string,ll>months;
    months.insert({"01",31});
    months.insert({"02",28});
    months.insert({"03",31});
    months.insert({"04",30});
    months.insert({"05",31});
    months.insert({"06",30});
    months.insert({"07",31});
    months.insert({"08",31});
    months.insert({"09",30});
    months.insert({"10",31});
    months.insert({"11",30});
    months.insert({"12",31});
    map<string,ll>years;
    years.insert({"2013",3});
    years.insert({"2014",4});
    years.insert({"2015",5});
    string s;
    cin>>s;
    map<string,ll>M;
    for (size_t i = 9; i < s.size(); i++)
    {
        if(s[i-9]<'0'||s[i-9]>'9')
            continue;
        if(s[i-8]<'0'||s[i-8]>'9')
            continue;
        if(s[i-7]!='-')
            continue;
        if(s[i-6]<'0'||s[i-6]>'9')
            continue;
        if(s[i-5]<'0'||s[i-5]>'9')
            continue;
        if(s[i-4]!='-')
            continue;
        if(s[i-3]<'0'||s[i-3]>'9')
            continue;
        if(s[i-2]<'0'||s[i-2]>'9')
            continue;
        if(s[i-1]<'0'||s[i-1]>'9')
            continue;
        if(s[i]<'0'||s[i]>'9')
            continue;
        string d=s.substr(i-9,10);
        if(M.find(d) == M.end())
            M.insert({d,1});
        else
            M[d]++;
    }
    string date;
    ll max=0;
    for (map<string, ll>::iterator itr = M.begin(); itr != M.end(); ++itr)
    {
        string d=itr->first;
        if(years[d.substr(6,4)]>0&&months[d.substr(3,2)]>0)
        {
            ll dd=stoll(d,NULL,10);
            if(dd>0&&dd<=months[d.substr(3,2)])
            {
                if(max<itr->second)
                {
                    max=itr->second;
                    date=d;
                }
            }
        }
    }
    cout<<date<<endl;
    return 0;
}
