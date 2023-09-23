#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    double i,n,x,y,x0,y0;
    cin>>n>>x>>y;
    set<double>s;
    for(i=0;i<n;i++)
    {
        cin>>x0>>y0;
        if(x!=x0)
        {
            //cout<<(y-y0)/(x-x0)<<endl;
            s.insert((y-y0)/(x-x0));
        }
        else
            s.insert(0xffffffff);
    }
    cout<<s.size()<<endl;
    return 0;
}
