#include <bits/stdc++.h>
using namespace std;
int search(vector<int>s[3],int x[3])
{
    int i,j,k;
    for(i=0;i<3;i++)
        for(j=0;j<s[0].size();j++)
            for(k=0;k<3;k++)
            {
                if(x[i]==s[j][k])
                    return 3*i+k;
            }
    return -1;
}
int main(int argc, char const *argv[])
{
    int i,j[3]={0,0,0},n,d,a[3];
    vector<int>v[3];
    cin>>n>>d;
    for(i=0;i<d;i++)
    {
        cin>>a[0]>>a[1]>>a[2];
        int x=search(v,a);
        if(x==-1)
        {
            for(int k=0;k<3;k++)
                v[k].push_back(a[k]);
        }
        else
        {
            v[x%3].push_back(a[x/3]);
            v[(x+1)%3].push_back(a[(x+1)/3]);
            v[(x+2)%3].push_back(a[(x+2)/3]);
        }
    }
    v[0].push_back(0x7fffffff);
    v[1].push_back(0x7fffffff);
    v[2].push_back(0x7fffffff);
    while((j[0]+j[1]+j[2])<n)
    {
        if(v[0][j[0]]<v[1][j[1]]&&v[0][j[0]]<v[2][j[2]])
        {
            cout<<1<<" ";
            j[0]++;
        }
        else if(v[1][j[1]]<v[0][j[0]]&&v[1][j[1]]<v[2][j[2]])
        {
            cout<<2<<" ";
            j[1]++;
        }
        else if(v[2][j[2]]<v[1][j[1]]&&v[2][j[2]]<v[0][j[0]])
        {
            cout<<3<<" ";
            j[2]++;
        }
    }
    cout<<endl;
    return 0;
}
//9179564142
