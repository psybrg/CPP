#include<bits/stdc++.h>
using namespace std;
int D(char* s,int r)
{
    int m=0,c;
    for(;c=*s++;m=m*r+c)
    {
        c-=48+(c>=65)*7;
        if(c>=r)
            return 60;
    }
    return m;
}
int main(){
	int i;
    char a[9],b[9];
    vector<int>u;
    scanf("%[0-9A-Z]:%[0-9A-Z]",a,b);
    for(i=2;i<61;i++)
		if(D(a,i)<=23&&D(b,i)<=59)
			u.push_back(i);
    if(u.empty())
        puts("0");
    else if(u.back()==60)
        puts("-1");
    else for(int x:u)
		printf("%d ",x);
    return 0;
}
