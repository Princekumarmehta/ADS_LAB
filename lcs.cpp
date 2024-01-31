#include <bits/stdc++.h>
#include <vector>
#include <set>

using namespace std;

set<string> allLCS;
int longestLength = 0; // Variable to store the length of the longest LCS

void findAllLCS(const vector<vector<pair<int, char>>> &dp, const string &text1, const string &text2, int i, int j, string current)
{
    if (i == 0 || j == 0)
    {
        reverse(current.begin(), current.end());
        if (current.size() == longestLength)
        {
            allLCS.insert(current);
        }
        return;
    }

    char dir = dp[i][j].second;

    if (text1[i - 1] == text2[j - 1])
    {
        findAllLCS(dp, text1, text2, i - 1, j - 1, text1[i - 1] + current);
    }

    if (dp[i - 1][j].first >= dp[i][j - 1].first)
    {
        findAllLCS(dp, text1, text2, i - 1, j, current);
    }

    if (dp[i][j - 1].first >= dp[i - 1][j].first)
    {
        findAllLCS(dp, text1, text2, i, j - 1, current);
    }
}

set<string> longestCommonSubsequences(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();

    vector<vector<pair<int, char>>> dp(m + 1, vector<pair<int, char>>(n + 1, {0, ' '}));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = {dp[i - 1][j - 1].first + 1, '\\'};
            }
            else
            {
                if (dp[i - 1][j].first >= dp[i][j - 1].first)
                {
                    dp[i][j] = {dp[i - 1][j].first, '|'};
                }
                else
                {
                    dp[i][j] = {dp[i][j - 1].first, '-'};
                }
            }
        }
    }

    longestLength = dp[m][n].first; // Set the length of the longest LCS

    // Print LCS Array
    cout << "LCS Array:" << endl;
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            cout << "(" << dp[i][j].first << "," << dp[i][j].second << ") ";
        }
        cout << endl;
    }
    findAllLCS(dp, text1, text2, m, n, "");

    return allLCS;
}

int main()
{
    string text1, text2;

    cout << "Enter the first string: ";
    cin >> text1;

    cout << "Enter the second string: ";
    cin >> text2;

    set<string> allLCS = longestCommonSubsequences(text1, text2);

    cout << "LCS Array and All Longest Common Subsequences:" << endl;

       // Print All Longest Common Subsequences
    cout << "All Longest Common Subsequences:" << endl;
    for (const string &lcs : allLCS)
    {
        string reversedLCS = lcs;
        reverse(reversedLCS.begin(), reversedLCS.end());
        cout << reversedLCS << endl;
    }

    // Print Length of Longest Common Subsequence
    cout << "Length of Longest Common Subsequence: " << longestLength << endl;

    return 0;
}
