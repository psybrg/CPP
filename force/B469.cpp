#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v)
{
    for (size_t i = 0; i < 10; i++)
        printf("%d ",v[i]);
    printf("\n" );
}
int isCommon(vector<int>a,vector<int>b,int j)
{
    for(int i=0;(i+j)<1008;i++)
        if((a[i+j]==b[i])&&(a[i+j]==1))
        {
            //cout<<i<<" ";
            return 1;
        }
    return 0;
}
int main(int argc, char const *argv[]) {
    int p,q,l,r,i,j,lo,hi,ans=0;
    vector<int>a(1008,0);
    vector<int>b(1008,0);
    cin>>p>>q>>l>>r;
    for(i=0;i<p;i++)
    {
        cin>>lo>>hi;
        for(j=lo;j<=hi;j++)
            a[j]=1;
    }
    for(i=0;i<q;i++)
    {
        cin>>lo>>hi;
        for(j=lo;j<=hi;j++)
            b[j]=1;
    }
    //print(a);
    //print(b);
    for(i=l;i<=r;i++)
        if(isCommon(a,b,i)==1)
            ans++;
    cout<<ans<<endl;
    return 0;
}
