#include <bits/stdc++.h>
using namespace std;
bool compareIncreasing(int i1, int i2)
{
	return (i1 < i2);
}

int main()
{
	int arr[]
		= {4,5,1,2,3};
	int n = sizeof(arr) / sizeof(arr[0]);

	// sort the intervals in increasing order of
	// start time
	sort(arr, arr + n, compareIncreasing);

	cout << "Intervals sorted by start time : \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout<<endl;

	return 0;
}
