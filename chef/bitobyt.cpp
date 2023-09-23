#include<bits/stdc++.h>
using namespace std;
long long int expo(int n)
{
    int i;long long int f=1;
    for(i=0;i<n;i++)
        f*=2;
    return f;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q,r,n;
        cin>>n;
        q=(n-1)/26;
        r=n%26;
        if((r>0)&&(r<=2))
            printf("%lld 0 0\n",expo(q));
        else if((r>2)&&(r<=10))
            printf("0 %lld 0\n",expo(q));
        else
            printf("0 0 %lld\n",expo(q));
    }
    return 0;
}