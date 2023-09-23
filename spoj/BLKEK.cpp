#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int l = 0,r=0;
        vector<int>left,right;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]=='K')
            {
                l++;
            }
            else if(s[i]=='E')
            {
                left.push_back(l);
            }
			if(s[s.size()-1-i]=='K')
			{
				r++;
			}
			else if(s[s.size()-1-i]=='E')
			{
				right.push_back(r);
			}
        }
		l=0;
		r=right.size()-1;
		while(l<r)
		{
			int x=right[l];
			right[l]=right[r];
			right[r]=x;
			l++;
			r--; 
		}
        if(left.size() < 1)
            cout<<0<<"\n";
        else
        {
			int sum=0;
			for (int i = 0; i < left.size(); i++)
			{
				sum+=left[i]*right[i];
			}
			cout<<sum<<"\n";
        }
    }
    return 0;
}