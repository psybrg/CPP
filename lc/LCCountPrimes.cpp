#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
   public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) ans++;
        }
        return ans;
    }
    int count(int n){
        int count = 0;
        vector <bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                for (int j = 2 * i; j < n; j = j + i) {
                    prime[j] = 0;
                }
            }
        }
        return count;
    }
};
int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    Solution solution;
    cout << solution.countPrimes(n) << "\n";
    return 0;
}
