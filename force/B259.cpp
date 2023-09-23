#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int arr[3][3];
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            cin>>arr[i][j];
    int x=-arr[0][1]-arr[0][2]+arr[1][0]+arr[1][2]+arr[2][0]+arr[2][1];
    int y=arr[0][1]+arr[0][2]-arr[1][0]-arr[1][2]+arr[2][0]+arr[2][1];
    int z=arr[0][1]+arr[0][2]+arr[1][0]+arr[1][2]-arr[2][0]-arr[2][1];
    arr[0][0]=x/=2;
    arr[1][1]=y/=2;
    arr[2][2]=z/=2;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
