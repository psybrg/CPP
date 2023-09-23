#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,t=0,r=1,MOD=1000003;
    string s;
    cin>>s;
    string ans="";
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='>')
            ans+="1000";
        else if(s[i]=='<')
            ans+="1001";
        else if(s[i]=='+')
            ans+="1010";
        else if(s[i]=='-')
            ans+="1011";
        else if(s[i]=='.')
            ans+="1100";
        else if(s[i]==',')
            ans+="1101";
        else if(s[i]=='[')
            ans+="1110";
        else if(s[i]==']')
            ans+="1111";
    }
    i=ans.length()-1;
    while(i>=0)
    {
        if(ans[i]=='1')
            t=(t%MOD+r%MOD)%MOD;
        r=(r*2)%MOD;
        i--;
    }
    cout<<t<<endl;
    return 0;
}
