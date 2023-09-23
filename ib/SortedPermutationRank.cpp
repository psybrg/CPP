#include<bits/stdc++.h>
using namespace std;
int/*Solution::/**/SortedPermutationRank(string A) {
    map<char,int>v;
    vector<int>fac;
    int i,n=A.length(),t=n-1,ans=1;
    fac.push_back(1);
    //vector<char>s;
    string s=A;
    sort(s.begin(),s.end());
    cout<<s<<endl;
    for(i=0;i<n;i++)
    {
    	v.insert(pair<char,int>(s[i],i));
    	fac.push_back((fac[i]%1000003*(i+1)%1000003)%1000003);
    	cout<<fac[i+1]<<endl;;
    }   
    for(i=0;i<n;i++,t--)
    {
    	printf("%d %d %d\n",A[i]-s[i],v[A[i]],v[s[0]]+1-i);
    	if(A[i]>s[i])
    		ans+=(fac[t]%1000003*((int)(v[A[i]]-v[s[0]]-i))%1000003)%1000003;
    }
    return ans;
}
int main()
{
	string n;
	cin>>n;
	cout<<SortedPermutationRank(n)<<endl;
	return 0;
}

