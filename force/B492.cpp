#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, n , l;
    cin>>n>>l;
    int arr[n+2];
    for (i = 1; i <= n; i++)
    	cin>>arr[i];
    sort(arr+1,arr+n+1);
    if(arr[1]!=0)
    	arr[0]=-arr[1];
    else arr[0]=0;
    if(arr[n]!=l)
    	arr[n+1]=2*l-arr[n];
    else arr[n+1]=l;
    double d,mx=arr[1]-arr[0];
	for (int i = 2; i < n+2; i++)
    {
        d = arr[i] - arr[i - 1];
        if (mx < d)
            mx = d;
    }
    printf("%.9lf\n",(mx/2));
    return 0;
}
