#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int x,n;
    cin>>n>>x;
    vector<int>a,b;
    for (int i = 0; i < n; i++)
    {
        int ai,bi;
        cin>>ai>>bi;
        if(ai>bi)
        {
            a.push_back(bi);
            b.push_back(ai);
        }
        else
        {
            a.push_back(ai);
            b.push_back(bi);
        }
    }
    int ax=a[0],bx=b[0];

    for (int i = 1; i < n; i++)
    {
        if(ax < a[i])
            ax = a[i];
        if(bx > b[i])
            bx = b[i];
    }
    if(ax > bx)
        cout<<-1;
    else if(ax <= x && bx >= x)
        cout<<0;
    else if(abs(ax-x)>abs(bx-x))
        cout<<abs(bx-x);
    else
        cout<<abs(ax-x);
    cout<<endl;
    return 0;
}
