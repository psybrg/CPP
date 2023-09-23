#include<bits/stdc++.h>
using namespace std;
int /*Solution::/**/hammingDistance(const vector<int> &A) {
    int i,j,c=0,ans=0;
    for(i=0;i<32;i++)
    {
        c=0;
        for(j=0;j<A.size();j++)
            if((A[j]&(1<<i))==0)
                c++;
        cout<<c<<endl;
        ans+=(2*((A.size()-c)%1000000007)*(c%1000000007))%1000000007;
    }
    return ans;
}
int main()
{
	int i,n,t;
	cin>>n;
	vector<int>v;
	for(i=0;i<n;i++)
	{
		cin>>t;
		v.push_back(t);
	}
	cout<<hammingDistance(v)<<endl;
	return 0;
}
