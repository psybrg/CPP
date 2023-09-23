#include <bits/stdc++.h>
using namespace std;
int main()
{
 	int i,j,n, m;
 	scanf("%d %d", &n, &m);
    int a[n],b[m];
 	for(int i = 0; i < n; i++)
 		scanf("%d", &a[i]);
   	for(int i = 0; i < m; i++)
   		scanf("%d", &b[i]);
   	int ans = n;
   	if (ans > m)
        ans = m;
   	for(int i = ans; i >= 0; i--)
    {
   	 	int ok = 1;
   	 	for(int j = 0; j < i; j++)
   	 	 	if (a[j] > b[m - i + j])
                ok = 0;
   		if (ok==1)
        {
   			printf("%d\n", n - i);
   			return 0;
   		}
    }
    return 0;
}
