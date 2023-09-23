#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,c4=0,c7=0;
    string s,t;
    cin>>s;
    vector<int>v;
    v.push_back(0);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='4')
            c4++;
        if(s[i]=='7')
            c7++;
    }
    if(c4>=c7&&c4>0)
        cout<<4<<endl;
    else if(c7>0)
        cout<<7<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
