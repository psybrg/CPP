#include<bits/stdc++.h>
using namespace std;
int man()
{
    multimap <int, int> m;
    m.insert(make_pair(1, 8));
    m.insert(make_pair(1, 5));
    m.insert(make_pair(2, 4));
    m.insert(make_pair(2, 3));
    m.insert(make_pair(3, 1));
    multimap<int,int>R;
    for (auto i=m.begin(); i!=m.end(); i++)
        R.insert({i->second,i->first});
    m.clear();
    for (auto i=R.begin(); i!=R.end(); i++)
        m.insert({i->second,i->first});
    for (auto i=m.begin(); i!=m.end(); i++)
        cout<<i->first<<"\t"<<i->second<<endl;
    return 0;
}
int main()
{
    /*Input : (10, "queen"), (20, "rose"), (5, "lion"), (20, "van"), (20, "watch"), (5, "joker")*/
    multimap <int, string> M;
    M.insert(make_pair(10, "queen"));
    M.insert(make_pair(20, "rose"));
    M.insert(make_pair(5, "lion"));
    M.insert(make_pair(20, "van")); // Duplicate value
    M.insert(make_pair(20, "watch")); // Duplicate value
    M.insert(make_pair(5, "apple"));
    multimap<string,int>R;
    for (auto i=M.begin(); i!=M.end(); i++)
        R.insert({i->second,i->first});
    M.clear();
    for (auto i=R.begin(); i!=R.end(); i++)
        M.insert({i->second,i->first});
    for (auto i=M.begin(); i!=M.end(); i++)
        cout<<i->first<<"\t"<<i->second<<endl;
    return 0;
}
#define ll long long int
int min(int argc, char const *argv[])
{
    cout<<sizeof(ll);
    printf(" %o",77);
    cout<<endl;
    return 0;
}
