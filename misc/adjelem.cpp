#include <bits/stdc++.h>
using namespace std;
string func(stack<char>st)
{
	string s="";
	while(st.empty()!=true)
	{
		s=st.top()+s;
		st.pop();
	}
	return s;
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{	
		string s;
		char ch;
		cin>>s;
		int i,n,t;
		stack<char>st;
		for(i=0;i<s.size();i++)
		{
			if(st.empty()||st.top()!=s[i])
			{	
				st.push(s[i]);
				cout<<func(st);
				cout<<endl;
				continue;
			}
			while(st.top()==s[i])
				i++;
			ch=st.top();
			st.pop();
			/*
			st.push(s[i]);
			cout<<func(st);
			cout<<endl;/**/
		}
		cout<<func(st)<<endl;
	}
	return 0;
}