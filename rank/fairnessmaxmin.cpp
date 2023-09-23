#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(),arr.end());
    int i,j,s,mn=arr[k-1]-arr[0];
    for(i=1,j=k;j<arr.size();i++,j++)
    {
        s=arr[j]-arr[i];
        if(mn>s)
            mn=s;
    }
    return mn;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);
    cout << result << "\n";
    return 0;
}
