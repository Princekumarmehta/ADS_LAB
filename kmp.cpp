#include <bits/stdc++.h>
using namespace std;

// aababcabcdabcdeabcdef
// abcdef
int total_comp = 0;
int kmp(string s, string p)
{
    int n1 = s.size();
    int n2 = p.size();
    int i = 0, j = 0, k;
    while (i <= n1 - n2)
    {
        total_comp++;
        if (p[0] == s[i])
        {
            j = 0;
            k = i;
            while (j < n2)
            {
                total_comp++;
                if (p[++j] != s[++k])
                    break;
            }
            if (j == n2)
                return i;
        }
        i = i + j;
        if (j == 0)
            i++;
    }
    return -1;
}

int main()
{
    string s1, s2;
    cout << "Enter string: \n";
    cin >> s1;
    cout << "Enter pattern to be searched in string: \n";
    cin >> s2;
    int index = kmp(s1, s2);
    if (index == -1)
        cout << "Pattern is not present in String ";
    else
    {
        cout << "Pattern is found at index " << index << ", after " << total_comp - 1 << " iteration(s)";
    }
    return 0;
}