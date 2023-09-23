#include<bits/stdc++.h>
using namespace std;
int MOD=1000000007;
map<pair<pair<int,int>,int>,int>mp;
int rec(int a[],int n,int i,int p,int pp)
{
    int x,s=0;
    if(i==0)
    {
        for(x=1;x<=a[i];x++)
        {
            if(mp[pair<pair<int,int>,int>(pair<int,int>(x,0),-1)]>0)
                s+=mp[pair<pair<int,int>,int>(pair<int,int>(x,0),-1)]%MOD;
            else
            {
                s+=rec(a,n,x,0,-1)%MOD;
                mp.insert(pair<pair<pair<int,int>,int>,int>(pair<pair<int,int>,int>(pair<int,int>(x,0),-1),s));
            }  
        }
        return 1+s;
    }
    for(x=-a[i];x<=a[i];x++)
        if(x==0)
            s++;
        else if(i+x>0&&i+x<n&&i+x!=p&&i+x!=pp)
        {
            if(mp[pair<pair<int,int>,int>(pair<int,int>(i+x,i),p)]>0)
                s+=mp[pair<pair<int,int>,int>(pair<int,int>(i+x,i),p)]%MOD;
            else
            {
                s+=rec(a,n,x+i,i,p)%MOD;
                mp.insert(pair<pair<pair<int,int>,int>,int>(pair<pair<int,int>,int>(pair<int,int>(i+x,i),p),s));
            }
        }
    return s;
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,s=0;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        s=rec(arr,n,0,-1,-1)%MOD;
        cout<<s<<endl;
        mp.clear();
    }
    return 0;
}
/*
	int x,y,z;
	for(size_t i = 0; i < 5; i++)
	{
		cin>>x>>y>>z;
		mp.insert(pair<pair<pair<int,int>,int>,int>(pair<pair<int,int>,int>(pair<int,int>(x,y),z),i));
	}
    cin>>x>>y>>z;
    cout<<mp[pair<pair<int,int>,int>(pair<int,int>(x,y),z)]<<endl;
/**/