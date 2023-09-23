#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t>=4)
    {
        cout<<"abcd";
        t-=4;
    }
    if(t==3)
        cout<<"abc\n";
    else if(t==2)
        cout<<"ab\n";
    else if(t==1)
        cout<<"a\n";
    else 
        cout<<"\n";
    return 0;
}