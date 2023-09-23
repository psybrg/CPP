#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int n,i,m,r,c,min;
    cin>>n>>m;
    //vector<vector<int>>v(n+1,vector<int>(n+1,0));
    vector<int> h(n+1,0);
    for(i=0;i<m;i++)
    {
        cin>>r>>c;
        h[r]++;
        h[c]++;
        //v[c][r]=v[r][c]=-1;
    }
    min=1;
    for(i=2;i<h.size();i++)
        if(h[min]>h[i])
            min=i;
    if(h[min]==0)
    {
        cout<<(n-1)<<endl;
        for (i = 1; i<=n; i++)
            if(min!=i)
                cout<<min<<" "<<i<<endl;
    }
    return 0;
}
