#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int i,n;
    cin>>n;
    vector<pair<int,int>>a(n,pair<int,int>(0,0));
    for(i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    int best = -1;
    for(int i = 0; i < n; i++)
        if (best <= a[i].second)
    		best = a[i].second;
        else
    	 	best = a[i].first;
    cout<<best<<endl;
    return 0;
}
