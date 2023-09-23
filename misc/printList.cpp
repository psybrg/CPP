#include <bits/stdc++.h>
#define ll long long int
using namespace std;

template <typename T>
void prnt(vector<T> v)
{
    cout << "[";
    cout << "\"" << v[0] << "\"";
    for (int i = 1; i < v.size(); i++)
        cout << ", " << "\"" << v[i] << "\"";
    cout << "]\n";
}

int main()
{
    int n;
    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < n; i++)
        cin >> vs[i];
    prnt(vs);
    return 0;
}
