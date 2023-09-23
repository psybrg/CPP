#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int i,n,t,x;
    cin>>n;
    //int home[n],away[n],ans[n]={n-1},hash[100003]={0};
    vector<int>home,away;
    vector<int>hash(100003,0);
    vector<int>ans(n,n-1);
    for(i=0;i<n;i++)
    {
        cin>>t>>x;
        hash[t]++;
        home.push_back(t);
        away.push_back(x);
    }
    for(i=0;i<n;i++)
    {
        ans[i]=ans[i]+hash[away[i]];
    }
    for(i=0;i<n;i++)
        cout<<ans[i]<<" "<<2*n-2-ans[i]<<endl;
    return 0;
}
