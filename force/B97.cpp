#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll gcd(ll a,ll b){
    if(a==0&&b)
        return b;
    if(b==0&&a)
        return a;
    if(a>b)
        return gcd(a%b,b);
    if(b>a)
        return gcd(a,b%a);
    return a;
}
void cancel(ll a,ll b){
    ll sign=0;
    if(a*b<0)
    {
        sign=1;
    }
    if(a<0)
        a=a*-1;
    if(b<0)
        b=b*-1;
    ll g=gcd(a,b);
    a=a/g;
    b=b/g;
    if(sign)
        cout<<"-"<<a<<"/"<<b<<endl;
    else
        cout<<a<<"/"<<b<<endl;
}
int main(int argc, char const *argv[]){
    ll n,m;
    cin>>n>>m;
    vector<ll>p,q;
    for (size_t i = 0; i <= n ; i++) {
        ll t;
        cin>>t;
        p.push_back(t);
    }
    for (size_t i = 0; i <= m ; i++) {
        ll t;
        cin>>t;
        q.push_back(t);
    }
    if(n>m){
        cout<<(p[0]*q[0]>0?"Infinity":"-Infinity")<<endl;
    }else if(m>n){
        cout<<"0/1"<<endl;
    }else{
        cancel(p[0],q[0]);
    }
    return 0;
}
