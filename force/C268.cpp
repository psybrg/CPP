#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
    int i,x,n,m;
    cin>>n>>m;
    int y=x=((n>m)?m:n);
    cout<<y+1<<endl;
    for (i = 0; i <= y; i++,x--) {
        printf("%d %d\n", i,x);
    }
    return 0;
}
