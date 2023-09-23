#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        char *t;
        scanf("%s",t);
        getline(s,cin);
        if(s.find("not ")!=string::npos)
            cout<<"Real fancy"<<endl;
        else if(s.find(" not ")!=string::npos)
            cout<<"Real fancy"<<endl;
        else if(s.find("not")!=string::npos)
            cout<<"Real fancy"<<endl;
        else
            cout<<"regular fancy"<<endl;
    }
    return 0;
}
