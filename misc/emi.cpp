#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll getAmount(ll p,ll r,ll t,ll s)
{
    return p*pow(1+r/(100*s),t*s);
}
int main(int argc, char const *argv[])
{
    ll r,emi,t,p,s=1;
    printf("P\tR\tT\tEmiPay\n");
    cin>>p>>r>>t>>emi;
    ll opening=p;
    ll total=getAmount(p,r,t,s);
    ll emipay=emi;
    ll closing=total-emipay;
    do
    {
        printf("%lld\t%lld\t%lld\t%lld\n", opening,total,emipay,closing);
        opening=closing;
        total=getAmount(opening,r,t,s);
        closing=total-emipay;
    }
    while(closing>0);
    printf("%lld\t%lld\t%lld\t%lld\n", opening,total,emipay,closing);
    cout<<endl;
    return 0;
}
