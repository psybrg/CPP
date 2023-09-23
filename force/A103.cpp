#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<long long int>a;
    long long int n,sum=0;
    cin>>n;
    for (long long int i = 0; i < n; i++)
    {
        long long int t;
        cin>>t;
        a.push_back(t);
    }
    for (long long int i = n - 2; i >= 0; i--)
    {
        a[i]+=a[i+1]-1;
    }
    for (long long int i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}
