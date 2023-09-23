#include<bits/stdc++.h>
using namespace std;
int fn(int n){
	if (n<=0) return 0;
	vector<int>dp(n+1,1);
	dp[2] = 2;
	for(int i=3;i<=n;i++){
		int s=0;
		for(int j=0;j<i;j++){
			s+=dp[j]*dp[i-j-1];
		}
		dp[i]=s;
	}
	return dp[n];
}
int main(){
	int n;
	cin>>n;
	cout<<fn(n)<<"\n";
}