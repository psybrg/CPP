#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,s;
    getline(cin,a);
    s=a;
    int i,n=a.length();
    vector<int>fwd,bwd;
    for(i=0;i<n-1;i++)
    {
        if(a[i]=='0'||a[i]=='2'||a[i]=='4'||a[i]=='6'||a[i]=='8')
        {
            if(s[n-1]>s[i])
                fwd.push_back(i);
            else
                bwd.push_back(i);
        }
    }
    if(fwd.size()>0)
    {
        char tmp=s[n-1];
        s[n-1]=s[fwd[0]];
        s[fwd[0]]=tmp;
        cout<<s<<endl;
    }
    else if(bwd.size()>0)
    {
        char tmp=s[n-1];
        s[n-1]=s[bwd[bwd.size()-1]];
        s[bwd[bwd.size()-1]]=tmp;
        cout<<s<<endl;
    }
    else
        cout<<-1<<endl;
    return 0;
}
