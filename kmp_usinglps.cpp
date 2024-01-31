#include <bits/stdc++.h>
using namespace std;

void computeLps(string a, vector<int> &lps)
{
    int length = 0;
    int i = 1;
    while (i < a.size())
    {
        if (a[i] == a[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string text, string pattern)
{
    int n1 = text.size();
    int n2 = pattern.size();
    vector<int> lps(n2, 0);
    computeLps(pattern, lps);
    int i = 0; // Index for text
    int j = 0; // Index for pattern
    int shifts = 0;
    while (i < n1)
    {
        shifts++;
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == n2)
        {
            cout << "Pattern found at index " << i - j << " with " << shifts << " shifts" << endl;
            j = lps[j - 1];
        }
        else if (i < n1 && pattern[j] != text[i])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
    cout << "Pattern not found";
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to be searched: ";
    getline(cin, pattern);
    KMP(text, pattern);
    return 0;
}
