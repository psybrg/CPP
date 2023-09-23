#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,m;
	cin>>n>>m;
	string s0,s1,s2;
	/*
	vector<pair<string,string>>v;
    for(i=0;i<m;i++)
    {
    	cin>>s1>>s2;
    	v.push_back(make_pair(s1,s2));
    }
    sort();
    vector<string>ls;
    for(i=0;i<n;i++)
    {
    	cin>>s0;
    	ls.push_back(s0);
    }
    /**/
    map<string,string>mp;
    vector<string>ans;
    for(i=0;i<m;i++)
    {
    	cin>>s1>>s2;
    	//mp.insert(pair<string,string>(s1,s2));
    	mp.insert(make_pair(s1,s2));
    }
    for(i=0;i<n;i++)
    {
    	cin>>s0;
    	if(s0.length()>mp[s0].length())
    		ans.push_back(mp[s0]);
    	else
    		ans.push_back(s0);
    }
    for(i=0;i<ans.size();i++)
    	cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
