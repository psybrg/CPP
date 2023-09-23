#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int i,j,tmp,n,t,s=0,mx=0;
    cin>>n>>t;
    vector<int>v;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        v.push_back(tmp);
    }
    tmp=t;
    for(i=0;i<n;i++)
    {
        if(tmp>=v[i])
        {
            tmp=tmp-v[i];
            s++;
        }
        else
        {
            tmp=t;
            s=0;
            j=i;
            while(tmp>=v[j])
            {
                tmp=tmp-v[j];
                s++;
                j--;
            }
        }
        if(mx<s)
            mx=s;
    }
    cout<<mx<<endl;
    return 0;
}
