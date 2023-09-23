#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>v;
	string s;
	getline(cin,s);
	stringstream iss(s);
	while(!iss.eof())
	{
		int i;
		string t;
		iss>>t;
		if(stringstream(t)>>i)
			v.push_back(i);
	}
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
	return 0;
}
