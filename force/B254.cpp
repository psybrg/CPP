#include<bits/stdc++.h>
using namespace std;

template <typename T>
void prnt(vector<T>v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<"\t";
	cout<<endl;
}

void setJury(const vector<int>&months, const vector<int>&cmonths, vector<int>&dailyJudges, int month, int day, int jury, int duration)
{
    int end = cmonths[month-1] + day - 1;
    int start = end + 1 - duration;
    for (int i = start; i <= end; i++)
        dailyJudges[365 + i] += jury;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<int>months(12,0);
    vector<int>cmonths(12,0);
    vector<int>dailyJudges(730,0);
    int monthsday[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; i++)
        months[i] = monthsday[i];
    for (int i = 1; i < 12; i++)
        cmonths[i] = months[i-1];
    for (int i = 1; i < 12; i++)
        cmonths[i] += cmonths[i-1];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int mi,di,pi,ti;
        cin>>mi>>di>>pi>>ti;
        setJury(months, cmonths, dailyJudges, mi, di, pi, ti);
    }
    // prnt(months);
    // prnt(cmonths);
    int maxJury=0;
    for (int i = 0; i < dailyJudges.size(); i++)
        if(maxJury<dailyJudges[i])
            maxJury = dailyJudges[i];
    cout<<maxJury<<endl;
    return 0;
}
