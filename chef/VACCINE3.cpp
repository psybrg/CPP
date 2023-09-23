#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int g,p;
        cin>>g>>p;
        g--;
        vector<int>v(10);
        for (int i = 0; i < 10; i++)
        {
            cin>>v[i];
        }
        for (int i = 8; i >= 0; i--)
        {
            v[i]+=v[i+1];
        }
        cout<<(v[g+1]/p)<<" "<<v[g]/p<<endl;
    }
    return 0;
}
