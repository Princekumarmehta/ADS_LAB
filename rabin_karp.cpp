#include <bits/stdc++.h>
using namespace std;

const int q = 256;

int calculate_hash(string s)
{
    int score = 0;
    for (int i = 0; i < s.size(); i++)
    {
        score = (score * q + s[i]) % INT_MAX;
    }
    return score;
}

int rabinKarp(string s, string p)
{
    int p_score = calculate_hash(p);
    int n = p.size();
    int temp = 0;
    for (int i = 0; i <= s.size() - n; i++)
    {
        if (s[i] == p[0])
        {
            temp = calculate_hash(s.substr(i, n));
            if (temp == p_score)
                return i;
        }
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
    int index = rabinKarp(s1, s2);
    if (index == -1)
        cout << "Pattern is not present in String ";
    else
    {
        cout << "Pattern is found at index " << index << ", after " << index + 1 << " iteration(s)";
    }
    return 0;
}
