#include<bits/stdc++.h>
using namespace std;
void push(vector<int>&v,int x)
{
	v.push_back(x);
}
int check(string s)
{
	int i=1;
	for(i=1;i<s.size();i++)
	{
		if(s[i]!=s[i-1])
			break;
	}
	if(i==s.size())
		return 0;
	for(i=1;i<s.size();i++)
	{
		if(s[i]>=s[i-1])
			break;
	}
	if(i==s.size())
		return 1;
	return 2;
}
void prnt(vector<int>v,vector<string>vs)
{
	cout<<vs[v[0]];
	for (int i = 1; i < v.size(); i++) {
		cout<<", "<<vs[v[i]];
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<string>nms;
	vector<vector<int>>res(n+1,vector<int>(3,0));
	for (int i = 0; i < n; i++)
	{
		int t;
		string s;
		cin>>t>>s;
		nms.push_back(s);
		while(t--)
		{
			string st;
			cin>>st;
			st.erase(st.begin()+2);
			st.erase(st.begin()+4);
			int r=check(st);
			res[i][r]++;
		}
	}
	res[n][0]=res[0][0];
	res[n][1]=res[0][1];
	res[n][2]=res[0][2];
	for(int i=1;i<res.size()-1;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(res[n][j]<res[i][j])
			{
				res[n][j]=res[i][j];
			}
		}
	}
	vector<vector<int>>ans
	{
		{},{},{}
	};
	for(int i=0;i<res.size()-1;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(res[n][j]==res[i][j])
			{
				push(ans[j],i);
			}
		}
	}
	cout<<"If you want to call a taxi, you should call: ";
	prnt(ans[0],nms);
	cout<<".\nIf you want to order a pizza, you should call: ";
	prnt(ans[1],nms);
	cout<<".\nIf you want to go to a cafe with a wonderful girl, you should call: ";
	prnt(ans[2],nms);
	cout<<".\n";
	return 0;
}
