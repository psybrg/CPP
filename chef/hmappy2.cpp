#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a>b)
        return gcd(a%b,b);
    else
        return gcd(a,b%a);
}
int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,k,a,b,res,g;
        cin>>n>>a>>b>>k;
        g=gcd(a,b);
        g=(a*b)/g;
        res=n/a+n/b-2*(n/g);
        if(res<k)
            cout<<"Lose\n";
        else
            cout<<"Win\n";
    }
    return 0;
}
