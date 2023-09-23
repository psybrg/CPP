#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
int comp(char a,char b)
{
    if(a==b)
        return 1;
    if((a+'a'-'A')==b)
        return 1;
    if((a+'A'-'a')==b)
        return 1;
    return 0;
}
char toup(char c)
{
    if(c>='A'&&c<='Z')
        return c;
    return c-'a'+'A';
}
char tolo(char c)
{
    if(c>='A'&&c<='Z')
        return c-'A'+'a';
    return c;
}
string abbreviation(string a, string b) {
    int i=0,j=0;
    while(i<a.size()&&j<b.size())
    {
        if(comp(a[i],b[j])==1)
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    for(int k=i;k<a.size();k++)
        if(a[k]>='A'&&a[k]<='Z')
            return "NO";
    if(j==b.size())
        return "YES";
    return "NO";
}

int main()
{
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string a;
        getline(cin, a);
        string b;
        getline(cin, b);
        string result = abbreviation(a, b);
        cout << result << "\n";
    }
    return 0;
}
public static boolean isAbbreviatable(String a, String b)
{
    if (b.size() > a.size())
        return "NO";
    int i = 0;
    int j = 0;
    int lo = 0;
    while (i < a.size()){
        if (j >= b.size())
        {
            if (a[i]>='A'&&a[i]<='Z')
                return "NO";
            else
                i++;
        }
        else {
            if (a[i] == b[j])
            {
                i++;
                j++;
                // Update lo marker
                if (lo < b.size() && b[j] == b[lo])
                    lo++;
                if (lo < j)
                    lo = j;
            }
            else if (lo < b.size() && a[i]>='a'&&a[i]<='z' &&
                        toup(a[i]) == b[lo])
            {
                    i++;
                    lo++;
            }
            else if (a[i]>='A'&&a[i]<='Z')
            {
                if (j < lo)
                    j++;
                else
                    return "NO";
            }
                else i++;
        }
    }
    if (j >= b.size() || lo >= b.size())
        return "YES";
    return "NO";
}
