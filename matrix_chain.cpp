#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> k)
{
    cout << endl;
    for (int i = 0; i < k.size(); i++)
    {
        for (int j = 0; j < k[i].size(); j++)
        {
            cout << k[i][j] << "\t";
        }
        cout << endl;
    }
}

void printParenthesisExpression(vector<vector<int>> k, int i, int j, char &matrixName)
{
    if (i == j)
    {
        cout << matrixName;
        matrixName++;
        return;
    }

    cout << "(";
    printParenthesisExpression(k, i, k[i][j], matrixName);
    printParenthesisExpression(k, k[i][j] + 1, j, matrixName);
    cout << ")";
}

void matrix(vector<int> d, int n)
{
    int row = n - 1;
    vector<vector<int>> dp(row, vector<int>(row, 0)), k(row, vector<int>(row, 0));
    int count = 1;
    while (count <= row)
    {
        for (int i = 0; i < row - count; i++)
        {
            int j = i + count;
            dp[i][j] = INT_MAX;

            for (int temp = i; temp < j; temp++)
            {
                int x = dp[i][temp] + dp[temp + 1][j] + (d[i] * d[temp + 1] * d[j + 1]);
                if (x < dp[i][j])
                {
                    dp[i][j] = x;
                    k[i][j] = temp;
                }
            }
        }
        count++;
    }
    cout << "Minimum number of multiplications needed: " << dp[0][row - 1] << endl;

    char matrixName = 'A';
    cout << "Optimal Parenthesization: ";
    printParenthesisExpression(k, 0, row - 1, matrixName);
    cout << endl;

    cout << "row" << endl;
    print(dp);
}

int main()
{
    int n;
    vector<int> d;

    cout << "Enter the number of elements in vector d: " << endl;
    cin >> n;

    cout << "\nEnter the elements for vector d: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        d.push_back(x);
    }

    matrix(d, n);

    return 0;
}
