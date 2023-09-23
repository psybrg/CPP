#include<bits/stdc++.h>
using namespace std;
vector<int>/*Solution::/**/maxset(vector<int> &A)
{
   long long int start=0, end=0, ansStart=0, length=0, ansLength=0, ansEnd=-1, s = INT_MIN, mx=INT_MIN;

   int i=0;
   
   while(i<A.size())
   {
       if(A[i]>=0)
       {
            start = i;
            s =0;
            length =0;     
            while(A[i]>=0 && i<A.size())
            {
                s +=A[i];
                i++;   
            }
            end = i-1;

            if((s>mx) || (s==mx && end-start+1<ansLength))
            {
               ansStart = start;
               ansEnd = end;
               ansLength = start + end -1 ;
               mx = s;
            }
       }
       i++;
    }
       vector <int> ans;
       for(i=ansStart; i<=ansEnd;i++){
           ans.push_back(A[i]);
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
	//cout<<kadane(v)<<endl;
	vector<int>ans=maxset(v);
	for(i=0;i<ans.size();i++)
		cout<<ans[i]<<"\t";
	cout<<endl;
	return 1;
}
