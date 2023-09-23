#include<bits/stdc++.h>
using namespace std;
int hammingDistance(const vector<int> &A) {
    long long int c=1,ans=0;
    for(long long int i=0;i<=31;i++)
    {
        long long int x=0,y=0;
        for(long long int j=0;j<A.size();j++)
        {
            if(c&A[j])
                x++;
            else
                y++;
            //cout<<x<<" "<<y<<endl;
        }
        c=c*2;
        ans+=(2*(x%1000000007)*(y%1000000007))%1000000007;
    }
    return ans;
}
int main (int argc, char const* argv[])
{
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	cout<<hammingDistance(v)<<endl;
	return 0;
}
