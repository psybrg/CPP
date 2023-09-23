#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int>hash1(26,0);
    vector<int>hash2(26,0);
    int i,s=0;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    for(i=0;s1[i]!='\0';i++)
        hash1[s1[i]-'a']++;
    for(i=0;s2[i]!='\0';i++)
        hash2[s2[i]-'a']++;
    for(i=0;i<26;i++)
        if(hash1[i]==0&&hash2[i]!=0)
        {
            cout<<-1<<endl;
            return 0;
        }
        else
            s+=(hash1[i]<hash2[i])?hash1[i]:hash2[i];
    cout<<s<<endl;
    return 0;
}
