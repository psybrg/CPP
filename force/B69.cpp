#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int m,n;
    cin>>n>>m;
    vector<int>l,r,t,c;
    for (int i = 0; i < m; i++)
    {
        int li,ri,ti,ci;
        cin>>li>>ri>>ti>>ci;
        l.push_back(li);
        r.push_back(ri);
        t.push_back(ti);
        c.push_back(ci);
    }
    vector<int>winner(n,-1);

    for (int i = 0; i < m; i++)
    {
        for (int j = l[i]; j <= r[i]; j++)
        {
            if(winner[j-1] != -1)
            {
                if(t[i] < t[winner[j-1]])
                {
                    winner[j-1] = i;
                }
            }
            else
                winner[j-1] = i;
        }
    }

    int P=0;
    for (int i = 0; i < winner.size(); i++)
    {
        if(winner[i] >= 0)
        {
            P += c[winner[i]];
        }
    }
    cout<<P<<endl;
    return 0;
}
