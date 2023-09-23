#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s,res="";
    cin>>s;
    int i,j=0;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='.')
        {
            if(i==s.size()-1)
            {
                res=".00";
            }
            else if(i==s.size()-2)
            {
                res="."+string(1,s[i+1])+"0";
            }
            else
            {
                res="."+string(1,s[i+1])+string(1,s[i+2]);
            }
            break;
        }
        else if(i==s.size()-1)
        {
            res=".00";
            break;
        }
    }
    if(i!=s.size()-1)
        i--;
    else if(s[i]=='.')
        i--;
    while(i>=0)
    {
        if(s[i]=='-')
        {
            break;
        }
        if(j==3)
        {
            j=0;
            res=','+res;
        }
        res=s[i]+res;
        i--;
        j++;
    }
    if(s[0]=='-')
    {
        res="($"+res+")";
    }
    else
    {
        res="$"+res;
    }
    cout<<res<<endl;
    return 0;
}
