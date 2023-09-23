#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,mx="";
    getline(cin,a);
    int i,n=a.length();
    for(i=0;i<n-1;i++)
    {
        string s=a;
        if(s[i]=='0'||s[i]=='2'||s[i]=='4'||s[i]=='6'||s[i]=='8')
        {
            char tmp=s[n-1];
            s[n-1]=s[i];
            s[i]=tmp;
            if(mx<s)
                mx=s;
        }
    }
    if(mx=="")
        cout<<-1<<endl;
    else 
        cout<<mx<<endl;
    return 0;
}