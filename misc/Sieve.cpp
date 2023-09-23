#include <bits/stdc++.h>
using namespace std;
vector<int> seive(int n) {
    int t = 0;
    vector<int> isPrime(n, 1);
    vector<int> spf(n, 2);
    vector<int> Prime;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            Prime.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < Prime.size() && i * Prime[j] < n && Prime[j] <= spf[i] /**/; j++) {
            isPrime[i * Prime[j]] = 0;
            spf[i * Prime[j]] = Prime[j];
            t++;
        }
    }
    cout << t << endl;
    return Prime;
    // return spf;
}
int main(int argc, char const* argv[]) {
    int i, n;
    cin >> n;
    vector<int> Prime = seive(n);
    for (i = 0; i < Prime.size(); i++) {
        cout << Prime[i] << "  ";
    }
    printf("\n");
    return 0;
}
