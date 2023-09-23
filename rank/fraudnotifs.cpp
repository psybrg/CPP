#include <bits/stdc++.h>
using namespace std;
int median(vector<int>v)
{
    int i,n=v.size(),d=v[v.size()-1],r=1+v[v.size()-1]/2;
    if(d%2==1)
        for(i=0;i<n;i++)
            if(v[i]>=r)
            {
                //cout<<2*i<<endl;
                return 2*i;
            }
    int lo,hi;
    for(i=0;i<n;i++)
        if(v[i]>=r)
        {
            hi=i;
            break;
        }
    r--;
    for(i=0;i<n;i++)
        if(v[i]>=r)
        {
            lo=i;
            break;
        }
    //printf("%d %d\n",lo,hi );
    return (lo+hi);
}
int activityNotifications(vector<int> expenditure, int d)
{
    int i,j,n=expenditure.size(),t=0;
    vector<int>h(201,0);
    for (i = 0; i < d; i++)
        h[expenditure[i]]++;
    for(i=d;i<n;i++)
    {
        vector<int>hh(h);
        for(j=1;j<hh.size();j++)
            hh[j]+=hh[j-1];
        int y=median(hh);
        //printf("[%d]->%d\n",i, y);
        if(expenditure[i]>=y)
            t++;
        h[expenditure[i]]++;
        h[expenditure[i-d]]--;
    }
    return  t;
}
int main()
{
    int n,d,t;
    cin>>n>>d;
    vector<int> expenditure;
    for (int i=0; i<n; i++)
    {
        cin>>t;
        expenditure.push_back(t);
    }
    cout<<activityNotifications(expenditure,d)<<endl;
}
