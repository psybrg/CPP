#include <bits/stdc++.h>
#define ll long long int
using namespace std;

template <typename T>
void prnt(vector<T>v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<"\t";
	cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> >gph(n,vector<int>(n,-1));
    for(int i = 1; i < n*(n-1)/2; i++)
    {
        int x, y;
        cin>>x>>y;
        gph[x-1][y-1]=1;
        gph[y-1][x-1]=0;
        gph[x-1][x-1]=0;
        gph[y-1][y-1]=0;
    }
    vector<int>score(n,0);
    int p1,p0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(gph[i][j] == 1)
                score[i]++;
            if(gph[i][j] == -1)
            {
                p0 = i;
                p1 = j;
            }
        }
    }
    // prnt(score);
    for(int i = 0; i < n; i++ )
    {
        if(i != p0 && score[i] == score[p0])
        {
            cout<<(p0+1)<<" "<<(p1+1)<<endl;
            return 0;
        }
        if(i != p1 && score[i] == score[p1])
        {
            cout<<(p1+1)<<" "<<(p0+1)<<endl;
            return 0;
        }
    }
    return 0;
}
