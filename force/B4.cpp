#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int f=1,m;
    cin>>m;
    if(m==5)
    {
        f=0;
        vector<int>v(5,0);
        for(int k = 0; k < m; k++)
        {
            int x,y;
            cin>>x>>y;
            v[x-1]++;
            v[y-1]++;
        }
        for(int k = 0; k < 5; k++)
        {
            if(v[k]!=2)
            {
                f = 1;
                break;
            }
        }
    }
    if(f>0)
        cout<<"WIN\n";
    else
        cout<<"FAIL\n";
    return 0;
}
