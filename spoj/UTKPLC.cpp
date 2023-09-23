#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<string>pref(3);
        cin>>pref[0];
        cin>>pref[1];
        cin>>pref[2];
        vector<string>ofr(3);
        cin>>ofr[0];
        cin>>ofr[1];
        for (int i = 0; i < 3; i++)
        {
            int j=0;
            for (; j < 2; j++)
            {
                if(pref[i]==ofr[j])
                {
                    cout<<pref[i]<<"\n";
                    break;
                }
            }
            if(j<2)
            {
                break;
            }
        }
    }
    return 0;
}