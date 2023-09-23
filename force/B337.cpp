#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a>b)
        return gcd(a%b,b);
    else
        return gcd(a,b%a);
}
int main(int argc, char const *argv[])
{
    int a,b,c,d,lcm,hcf;
    cin>>a>>b>>c>>d;
    if((double)a/(double)c>(double)b/(double)d)
    {
        lcm=b*d/gcd(b,d);
        a=a*lcm/b;
        c=c*lcm/d;
        hcf=gcd(a,c);
        a=a/hcf;
        c=c/hcf;
        printf("%d/%d\n",(a-c),a);
    }
    else
    {
        lcm=a*c/gcd(a,c);
        b=b*lcm/a;
        d=d*lcm/c;
        hcf=gcd(b,d);
        b=b/hcf;
        d=d/hcf;
        printf("%d/%d\n",(b-d),b);
    }
    return 0;
}