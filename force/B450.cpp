#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int main(int argc, char const *argv[]) {
    long int x,y,i,n;
    cin>>x>>y>>n;
    vector<int>v(12,0);
    v[0]=0;
    v[1]=x;
    v[2]=y;
    for (i = 3; i <12; i++)
        v[i]=(v[i-1]%MAX-v[i-2]%MAX)%MAX;
    n=6+n%6;
    /*
    for(i=0;i<v.size();i++)
        if(i%3==0)
            cout<<v[i]<<"\t";
        else
            cout<<"\n"<<v[i]<<"\t";
            /**/
    if(v[n]>=0)
        cout<<v[n]%MAX<<endl;
    else
        cout<<(MAX+v[n])%MAX<<endl;
    return 0;
}
