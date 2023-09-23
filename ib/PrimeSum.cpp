#include<bits/stdc++.h>
using namespace std;
int isPrime(int A)
{
    for(int i=2;i<=sqrt(A)+2&&i<A;i++)
        if(A%i==0)
            return 0;
    return 1;
}
vector<int>/*Solution::/**/primesum(int A) {
    int i=2,j;/*,sv[1000000]={1};
    while(i<1000000)
    {
        j=i;
        while(j<i)
        {
            
        }
    }/***/
    vector<int>ans;
    while(i<A)
    {
        if(isPrime(i))
        {
            if(isPrime(A-i))
            {
                ans.push_back(i);
                ans.push_back(A-i);
                break;
            }
        }
        i++;
    }
    return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int>v=primesum(n);
	cout<<n<<" = "<<v[0]<<" + "<<v[1]<<endl;
	return 0;
}
