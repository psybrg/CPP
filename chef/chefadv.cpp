#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long int n,m,x,y,n1=1,m1=1;
        cin>>n>>m>>x>>y;
        /*
        long int n1,m1,arr[2][3];
        arr[0][0]=n/x;
        arr[0][1]=n%x;
        arr[1][0]=m/y;
        arr[1][1]=m%y;
        n1=arr[0][0]*x+arr[0][1];
        m1=arr[1][0]*x+arr[1][1];
        cout<<n1<<m1;/**/
        if(n==n1&&m==m1)
            cout<<"Chefirnemo"<<endl;
        else if(n==(n1+1)&&m==(m1+1))
            cout<<"Chefirnemo"<<endl;
        else
            cout<<"Pofik"<<endl;
        /*
        if(x>n||y>m)
            cout<<"Pofik"<<endl;
        else if(((n-1)%x==0)&&((m-1)%y==0))
            cout<<"Chefirnemo"<<endl;
        else if(((n-2)%x==0)&&((m-2)%y==0))
            cout<<"Chefirnemo"<<endl;
        else
            cout<<"Pofik"<<endl;/**/
    }
    return 0;
}