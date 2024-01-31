#include <bits/stdc++.h>
using namespace std;

const int q = 256;
vector<int> indexes;
int it = 0;
int calculate_hash(string s)
{
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        ans += ((s[i] - 'a') * q) % INT_MAX;
    }
    return ans;
}

int rabinKarp(string s, string p)
{
    int score = calculate_hash(p);
    int n1 = s.size();
    int n2 = p.size();
    int i = 0;
    while (i <= n1 - n2)
    {
        if (s[i] == p[0])
        {
            int temp = calculate_hash(s.substr(i, n2));
            if (temp == score)
                indexes.push_back(i);
        }
        i++;
    }
    return -1;
}
int main()
{
    string s1;
    string s2;
    cout << "Enter string for search: ";
    getline(cin, s1);
    cout << "\n Enter patern to be searched in string: ";
    getline(cin, s2);
    int ii = rabinKarp(s1, s2);
    if (indexes.size() == 0)
        cout << "Not found";
    else
    {
        for (int i = 0; i < indexes.size(); i++)
        {
            cout << "pattern is found at " << indexes[i] << endl;
        }
    }
    return 0;
}