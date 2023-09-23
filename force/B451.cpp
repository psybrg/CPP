#include <bits/stdc++.h>
using namespace std ;
int isSorted(std::vector<int> v)
{
    for (size_t i = 1; i < v.size(); i++)
        if (v[i-1]>v[i])
            return 0;
    return 1;
}
int main(int argc, char const *argv[])
{
    vector <int> v;
    vector <pair<int,int>>pv;
    int start=0,end=0,i,n,t,x=1;
    cin>>n;
    cin>>t;
    v.push_back(t);
    for (i = 1; i < n; i++)
    {
        cin>>t;
        v.push_back(t);
        if(v[i]<v[i-1])
        {
            x++;
            end++;
        }
        else
        {
            x=1;
            if(start!=end)
                pv.push_back(make_pair(start,end));
            start=end=i;
        }
    }
    if(start!=end)
        pv.push_back(make_pair(start,end));

        /*

    for (i = 0; i < pv.size(); i++)
        cout << '\t'<<pv[i].first<<"\t"<<pv[i].second<<endl;
    cout<<endl;/**/
    if(isSorted(v))
        cout<<"yes"<<endl<<1<<" "<<1<<endl;
    else if(pv.size()==1)
    {
        sort(v.begin()+pv[0].first,v.begin()+pv[0].second+1);
        /*
        for (i = 0; i < v.size(); i++)
            cout <<v[i]<<"\t";
        cout<<endl;/***/

        if(isSorted(v))
            cout<<"yes"<<endl<<pv[0].first+1<<" "<<pv[0].second+1<<endl;
        else
            cout<<"no"<<endl;
    }else
        cout<<"no"<<endl;
    return 0;
}
