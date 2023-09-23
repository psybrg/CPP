#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define maX(a,b)                ((a)>(b)?(a):(b))
#define miN(a,b)                ((a)<(b)?(a):(b))
#define abS(x)                    ((x)<0?-(x):(x))
#define s(n)                    scanf("%d",&n)
#define sl(n)                     scanf("%lld",&n)
#define sf(n)                     scanf("%lf",&n)
#define ss(n)                     scanf("%s",n)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin >> n >> m;
    ll a[m][3];ll flag=0;
    if(n/m==3)
    flag=1;
    map<ll ,ll> mp;ll hash[n]={0};
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<3;j++)
        {
            cin >> a[i][j];
            if(flag==1)
            mp[a[i][j]]=3-j;
            else
            mp[a[i][j]]=0;
        }
 
    }
    if(flag==0)
    {
        for(ll i=0;i<m;i++)
        {
          int b=6;
          if(i==0)
          { mp[a[i][0]]=1;mp[a[i][1]]=2;mp[a[i][2]]=3; }
          else
          {
             if(mp[a[i][0]]!=0 || mp[a[i][1]]!=0 || mp[a[i][2]]!=0)             
             {
                if(mp[a[i][0]]!=0)
                {
                    b=b-mp[a[i][0]];
                    if(b==5)
                        mp[a[i][1]]=3,mp[a[i][2]]=2;
                    else if(b==4)
                        mp[a[i][1]]=1,mp[a[i][2]]=3; 
                    else
                        mp[a[i][1]]=1,mp[a[i][2]]=2; 
 
                }
                else if(mp[a[i][1]]!=0)
                {
                    b=b-mp[a[i][1]];
                    if(b==5)
                        mp[a[i][0]]=3,mp[a[i][2]]=2;
                    else if(b==4)
                        mp[a[i][0]]=1,mp[a[i][2]]=3; 
                    else
                      mp[a[i][0]]=1,mp[a[i][2]]=2; 
                }
                else
                {
                    b=b-mp[a[i][2]];
                    if(b==5)
                        mp[a[i][0]]=3,mp[a[i][1]]=2;
                    else if(b==4)
                      mp[a[i][0]]=1,mp[a[i][1]]=3; 
                    else
                      mp[a[i][0]]=1,mp[a[i][1]]=2; 
                }
 
             }
             else
               mp[a[i][0]]=1,mp[a[i][1]]=2,mp[a[i][2]]=3;
          }  
 
          }      
        }
    map<ll, ll>::iterator it; 
    for(it=mp.begin();it!=mp.end();it++)
    cout << it->second << " ";
    cout << endl;
return 0;
}
