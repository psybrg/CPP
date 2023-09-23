#include<bits/stdc++.h>
using namespace std;/*
int/*Solution::/*trailingZeroes(int A) {
    int j,i=5,ans=0;
    while(i<=A)
    {
        j=i;
        while(j%5==0)
        {
            ans++;
            j=j/5;
        }i=i+5;
    }
    return ans;
}/**/
int/*Solution::/**/trailingZeroes(int A) {
    int ans=0;
    while(A)
    {
        ans+=A/5;
        A/=5;
    }
    return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<trailingZeroes(n)<<endl;
	return 0;
}
