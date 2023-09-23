#include<bits/stdc++.h>
using namespace std;
int main()
{
    long n, m = 0, k = 0, a, b, c = 0, d = 0;
    cin>>n;
    long t[n];
    for(long i = 0; i < n; i++)
    {
        cin>>t[i];
        m+=t[i];
    }
    if(m%n!=0)
    {
        cout<<"Unrecoverable configuration.";
        return 0;
    }
    m/=n;
    a=m;
    b=m;
    for(long i = 0; i < n; i++)
    {
        if(t[i]>a){a=t[i];c=i;
    }
    if(t[i] < b)
    {
        b=t[i];
        d=i;
    }
    if(t[i] != m)
        k++;
    }
    if(k == 0)
        cout<<"Exemplary pages.";
    else if(k == 2)
        cout<<(a-b)/2<<" ml. from cup #"<<d+1<<" to cup #"<<c+1<<".";
    else
        cout<<"Unrecoverable configuration.";
    return 0;
}
