#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
	public:
	    char getUniqueChar(vector<char>chars) {
	        for(int i=0;i<chars.size();i++) {
	            if(chars[i] >= 'a' && chars[i] <= 'z') {
	                return chars[i];
	            }
	        }
	        return '#';
	    }
		string FirstNonRepeating(string A){
		    vector<int>hash(26, 0);
		    vector<char>chars;
		    for(int i=0;i<A.size();i++) {
	            hash[A[i]-'a']++;
	            if(hash[A[i]-'a'] == 1) {
	                chars.push_back(A[i]);
	            }
	            else {
	                for(int j=0;j<chars.size();j++) {
	                    if(chars[j] == A[i]) {
	                        chars[j] = '#';
	                        break;
	                    }
	                }
	            }
	            A[i] = getUniqueChar(chars);
		    }
		    return A;
		}

};

int main(int argc, char const *argv[]) {
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string k;
        cin >> k;
        Solution sol;
        cout << sol.FirstNonRepeating(k) << "\n";
    }
    return 0;
}