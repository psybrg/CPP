#include <bits/stdc++.h>
using namespace std;

string convertToNewString(const string &s) {
    string newString = "@";
    for (int i = 0; i < s.size(); i++) {
        newString += "#" + s.substr(i, 1);
    }
    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s) {
    string str = convertToNewString(s);

    // current center, right limit
    int c = 0, r = 0;

    // augmentation array containing palindrome length
    vector<int> aug(str.size() + 1, 0);
    for (int i = 1; i < str.size() - 1; i++) {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if (r > i) {
            aug[i] = min(r - i, aug[iMirror]);
        }

        // expanding around center i
        while (str[i + 1 + aug[i]] == str[i - 1 - aug[i]]) {
            aug[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + aug[i] > r) {
            c = i;  // next center = i
            r = i + aug[i];
        }
    }

    // Find the longest palindrome length in p.
    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < str.size() - 1; i++) {
        if (aug[i] > maxPalindrome) {
            maxPalindrome = aug[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr((centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main() {
    string s = "kiomaramol\n";
    cout << longestPalindromeSubstring(s);
    return 0;
}