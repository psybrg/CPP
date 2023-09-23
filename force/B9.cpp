#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,idx;
    double b,s,min=1e12;
    cin>>n>>b>>s;
    vector<int>a(n,0);
    for(i=0;i<n;i++)cin>>a[i];
    double x,y;
    cin>>x>>y;
    for(i=1;i<n;i++)
    {
        double t1=sqrt((a[i]-x)*(a[i]-x)+y*y)/s+a[i]/b;
        if(t1<=min)min=t1,idx=i;
    }
    cout<<idx+1<<endl;
    return 0;
}
