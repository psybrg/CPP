#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(int argc, char const *argv[])
{
    ll n,m,d=1;
    cin>>n>>m;
    ll mid=(m+1)/2;
    vector<ll>v;
    v.push_back(mid);
    if(m%2==1){
        while(mid>d){
            v.push_back(mid-d);
            v.push_back(mid+d);
            d++;
        }
    }
    else{
        while(mid>d){
            v.push_back(mid+d);
            v.push_back(mid-d);
            d++;
        }
        v.push_back(m);
    }
    for (size_t i = 0,j=0; i < n; i++,j=(j+1)%v.size())
        cout<<v[j]<<endl;
    return 0;
}
