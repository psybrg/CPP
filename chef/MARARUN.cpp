#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int D,d,A,B,C;
        cin>>D>>d>>A>>B>>C;
        if(D*d<10)
            cout<<0;
        else if(D*d<21)
            cout<<A;
        else if(D*d<42)
            cout<<B;
        else
            cout<<C;
        cout<<endl;
    }
    return 0;
}
