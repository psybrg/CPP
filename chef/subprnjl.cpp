#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/standard_policies.hpp> 
using namespace __gnu_pbds;
#define ordered_set tree<int, mapped_type,less<int>,
rb_tree_tag,tree_order_statistics_node_update> 
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,k,l,r,x,ans=0;
        cin>>n>>k;
        vector<ordered_set>sh;
        ordered_set os;
        for(i=0;i<n;i++)
        {
            cin>>x;
            os.insert(x);
            sh.push_back(os);
        }
        for(l=0;l<n;l++)
            for(r=l;r<n;r++)
                if(l==r&&os.order_of_key(2)>os.order_of_key(1))
                    ans++;
                else
                {
                    int m=ceil(k/(r-l+1));
                    int j=k/m+k%m;
                    x=os.find_by_order(r-l+j);
                    if(sh[r][x]>sh[l-1][x])
                        ans++;
                }
                
    }
    return 0;
}
