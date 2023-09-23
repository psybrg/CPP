#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int get(vector<long int>v,int i)
{
    if(i<0)
        return 0;
    return v[i];
}
int main(int argc, char const *argv[]) {
    int n,k,d,i,j;
    long int s;
    cin>>n>>k>>d;
    vector<long int>vk,vd;
    vk.push_back(1);
    vd.push_back(1);
    if(d>n)
        cout<<0<<endl;
    else
    {    
        if(k>n)
            k=n;
        for(i=0;i<=n;i++)
        {
            s=j=0;
            while(j<k)
            {
                s=(s%MOD+get(vk,i-j)%MOD)%MOD;
                j++;
            }
            vk.push_back(s);
            if(d==2)
            {
                vd.push_back(1);
                continue;
            }
            s=j=0;
            while(j<(d-1))
            {
                s=(s%MOD+get(vd,i-j)%MOD)%MOD;
                j++;
            }
            vd.push_back(s);
        }
        /*
        for (size_t z = 0; z < vk.size(); z++)
            cout<<vk[z]<<"\t";
        cout<<endl;
        for (size_t z = 0; z < vd.size(); z++)
            cout<<vd[z]<<"\t";
        cout<<endl;/**/
        long int ans = ((vk[n]-vd[n])>0)?(vk[n]-vd[n]):(MOD+vk[n]-vd[n]);
        cout<<ans<<endl;
    }
    return 0;
}
