#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int a,b,k;
        cin>>a>>b>>k;
        if(((a+b)/k)%2==0)
            cout<<"CHEF"<<endl;
        else
            cout<<"COOK"<<endl;
    }
    return 0;
}