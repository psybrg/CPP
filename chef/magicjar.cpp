#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    while(t--)
    {
        long int i,n,t,s=1;
        cin>>n;
        vector<int>v;
        for(i=0;i<n;i++)
        {
            cin>>t;
            v.push_back(t);
            s+=t-1;
        }
        cout<<s<<endl;
    }
    return 0;
}
