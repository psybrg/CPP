#include <bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s)
{
    stack<pair<char,int>>q;
        int ans=0,mx=0,sx=s.size(),ex=s.size(),ss=s.size(),es=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                q.push({s[i],i});
            else if(s[i]==')'&&q.size()>0)
            {
                pair<char,int>p=q.top();
                q.pop();
                ss=p.second;
                es=i;
                ans+=2;
                if((ex+1)==ss)
                {
                    ex=es;
                }
                else if((es-ss)>(ex-sx))
                {
                    ex=es;
                    sx=ss;
                    cout<<sx<<" "<<ex<<endl;
                }
            }
        }
        if(ex==sx) return 0;
        return (ex-sx+1);
    }
int lp(string s)
{
    vector<int>v(s.size(),-1);
    stack<pair<char,int>>q;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
           q.push({s[i],i});
        else if(s[i]==')'&&q.size()>0)
        {
            pair<char,int>p=q.top();
            q.pop();
            v[p.second]=0;
            v[i]=0;
        }
    }
    int k=0,mx=0;
    for(int i=0;i<s.size();i++)
    {
        if(v[i]==-1)
            k=0;
        else
            k++;
        if(mx<k)
            mx=k;
    }
    return mx;
}
int main()
{
    string s;
    cin>>s;
    cout<<lp(s);
    return 0;
}
