#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename V>
void prnt(vector<V> v)
{
	for(size_t i = 0; i < v.size(); i++)
	{
		cout<<v[i];
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    vector<string>vs;
    vector<ll>v;
    for (ll i = 0; i < s.size(); i++)
    {
        if(s[i]=='@')
            v.push_back(i);
        else if(s[i]<'a'||s[i]>'z')
        {
            cout<<"No solution\n";
            return 0;
        }
    }
    ll lo=0;
    for (ll i = 1; i < v.size(); i++)
    {
        if(v[i-1]==0||v[i]==(s.size()-1))
        {
            cout<<"No solution\n";
            return 0;
        }
        if(v[i]-v[i-1]<3)
        {
            cout<<"No solution\n";
            return 0;
        }
        ll hi=v[i-1]+(v[i]-v[i-1])/2;
        vs.push_back(s.substr(lo,hi-lo+1)+',');
        lo=hi+1;
    }
    if(s[0]!='@'&&s[s.size()-1]!='@'&&v.size()>0)
        vs.push_back(s.substr(lo,s.size()-lo+1));
    else
    {
        cout<<"No solution\n";
        return 0;
    }
    prnt(vs);
    return 0;
}
