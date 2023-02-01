#include <bits/stdc++.h>
using namespace std;

// recursion + memoization

int minimumDeleteSum(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    return fun(n1, n2, s1, s2, dp);
}
int fun(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{

    if (i == 0 && j == 0)
    {
        return 0;
    }
    if (i == 0 && j > 0)
    {
        int sum = 0;
        for (int ind = 1; ind <= j; ind++)
        {
            sum += (int)s2[ind - 1];
        }
        return sum;
    }
    if (j == 0 && i > 0)
    {
        int sum = 0;
        for (int ind = 1; ind <= i; ind++)
        {
            sum += (int)s1[ind - 1];
        }
        return sum;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s1[i - 1] == s2[j - 1])
    {
        return dp[i][j] = fun(i - 1, j - 1, s1, s2, dp);
    }
    return dp[i][j] = min((int)s1[i - 1] + fun(i - 1, j, s1, s2, dp),
                          (int)s2[j - 1] + fun(i, j - 1, s1, s2, dp));
}

// tabulation

int minimumDeleteSum(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    for (int i = 1; i <= n1; i++)
    {
        dp[i][0] = (int)s1[i - 1] + dp[i - 1][0];
    }
    for (int j = 1; j <= n2; j++)
    {
        dp[0][j] = (int)s2[j - 1] + dp[0][j - 1];
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {

            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
                dp[i][j] = min((int)s1[i - 1] + dp[i - 1][j],
                               (int)s2[j - 1] + dp[i][j - 1]);
        }
    }

    return dp[n1][n2];
}