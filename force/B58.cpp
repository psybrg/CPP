#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int i,n;
    cin>>n;
    vector<int>v;
    v.push_back(n);
    for(i=n/2;i>0;i--)
        if(n%i==0)
        {
            v.push_back(i);
            n=i;
        }
    for(i=0;i<v.size();i++)
        printf("%d ", v[i]);
    cout<<endl;
    return 0;
}
