#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll ans=1,z=0;
    vector<int>v;
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i]-'0'+s[i-1]-'0'==9)
            z++;
        else
        {
            if(z>1)
                v.push_back(z);
            z=0;
        }

    }
    if(z>1)
        v.push_back(z);
    for(int i = 0; i < v.size(); i++)
        if(v[i]%2==0)
		    ans*=v[i]/2+1;
    cout<<ans<<endl;
    return 0;
}
