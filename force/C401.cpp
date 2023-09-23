#include <bits/stdc++.h>
using namespace std ;
int main()
{
    int n,m,i;
    string s;
    cin>>n>>m;
    if((n-1)<=m&&m<=2*(n+1))
    {
        while((n+m)>0)
        {
            if(n==m)
            {
                s+="10";
                n--;
                m--;
            }
            else if(n==1&&m==0)
            {
                s+="0";
                n--;
            }
            else if(n==0&&m==2)
            {
                s+="11";
                m--;
                m--;
            }
            else if(n==0&&m==1)
            {
                s+="1";
                m--;
            }
            else if(m>n)
            {
                s+="110";
                n--;
                m--;
                m--;
            }
            else if(n>m)
            {
                s+="01";
                n--;
                m--;
            }
        }
        cout<<s<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}
