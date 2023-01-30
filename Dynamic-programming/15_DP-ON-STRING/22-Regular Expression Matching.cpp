#include <bits/stdc++.h>
using namespace std;

// recursion + memoization

bool isMatch(string s, string p)
{
    int n1 = s.size();
    int n2 = p.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    return fun(n1 - 1, n2 - 1, s, p, dp);
}

bool fun(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{

    if (i < 0 && j < 0)
    {
        return true;
    }
    if (j < 0 && i >= 0)
    {
        return false;
    }

    if (i < 0 && j >= 0)
    {
        int ind = j;
        while (ind >= 0)
        {
            if (p[ind] == '*')
            {
                ind -= 2;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (s[i] == p[j] || p[j] == '.')
    {
        return dp[i][j] = fun(i - 1, j - 1, s, p, dp);
    }
    if (p[j] == '*')
    {
        bool nottaken = fun(i, j - 2, s, p, dp);
        bool taken = false;
        if (s[i] == p[j - 1] || p[j - 1] == '.')
        {
            taken = fun(i - 1, j, s, p, dp);
        }
        return dp[i][j] = taken | nottaken;
    }
    return dp[i][j] = false;
}