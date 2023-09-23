#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    long long int r=0,b=0;
    int i,n,t,lastmove=0;
    vector<int>red,blu;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t;
        if(t>0)
        {
            red.push_back(t);
            r+=t;
            if(i==(n-1))
                lastmove=1;
        }
        else if(t<0)
        {
            blu.push_back(-t);
            b+=(-t);
            if(i==(n-1))
                lastmove=-1;
        }
    }
    if(r>b)
        cout<<"first\n";
    else if(b>r)
        cout<<"second\n";
    else
    {
        for(i=0;i<red.size()&&i<blu.size();i++)
        {
            if(red[i]>blu[i])
            {
                cout<<"first\n";
                return 0;
            }
            else if(red[i]<blu[i])
            {
                cout<<"second\n";
                return 0;
            }
        }
        if(lastmove>0)
            cout<<"first\n";
        else if(lastmove<0)
            cout<<"second\n";
    }
    return 0;
}
