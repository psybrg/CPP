#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k,j=0;
	cin>>n>>k;
	vector<int>v(2*n);
    for(int i=0;i<n;i++)
    {
        v[i]=i+1;
        v[2*n-1-i]=2*n-i;
    }
    for(int i=0;i<k;i++)
    {
        int x=v[j];
        v[j]=v[j+1];
        v[j+1]=x;
        j=j+2;
    }
    for (int i = 0; i < 2*n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
	return 0;
}
