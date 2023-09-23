#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    while(t--)
    {
        long int i,n,a,b,x,pa=0,pb=0,p=0;
        cin>>n>>a>>b;
        for(i=0;i<n;i++)
        {
            cin>>x;
            if (x%a==0)
                pa++;
            if (x%b==0)
                pb++;
            if(x%a==0&&x%b==0)
                p++;
        }
        pa-=p;
        pb-=p;
        if(pa==pb)
        {
            if(p%2==0)
                cout<<"ALICE"<<endl;
            else
                cout<<"BOB"<<endl;
        }
        else if(pa>pb)
        {
            cout<<"BOB"<<endl;
        }
        else
        {
            cout<<"ALICE"<<endl;
        }
    }
    return 0;
}
