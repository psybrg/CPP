#include<bits/stdc++.h>
using namespace std;
long substrCount(int n, string s)
{
    int i,c=1;
    long ans=0,ss=0;
    vector<int>vi;
    vector<char>vc;
    for(i=1;i<=n;i++)
    {
        if(s[i]==s[i-1])
            c++;
        else
        {
            //cout<<i<<"\n";
            vi.push_back(c);
            vc.push_back(s[i-1]);
            c=1;
        }
    }/*
    vi.push_back(c);
    vc.push_back(s[i-1]);/*
    for(i=0;i<vi.size();i++)
    {
    	ss+=vi[i];
    	if(i<100)
        cout<<vc[i]<<"\t"<<vi[i]<<endl;
    }
    cout<<ss<<endl;/**/
    for(i=0;i<vi.size();i++)
        ans+=vi[i]*(vi[i]+1)/2;
    for(i=1;i<vi.size()-1;i++)
        if(vi[i]==1)
            if(vc[i-1]==vc[i+1])
            {
                int min=(vi[i+1]<vi[i-1])?vi[i+1]:vi[i-1];
                ans+=min*(min+1)/2;
            }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    getline(cin, s);
    long result = substrCount(n, s);
    cout << result << "\n";
    return 0;
}

