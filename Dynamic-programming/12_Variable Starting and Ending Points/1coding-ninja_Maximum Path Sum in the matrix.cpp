#include <bits/stdc++.h>
using namespace std;

// Recursion and memoization

int fun(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j < 0 || j >= matrix[0].size())
    {
        return -1e8;
    }
    if (i == 0)
    {
        return matrix[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int dow = matrix[i][j] + fun(i - 1, j, matrix, dp);
    int lef = matrix[i][j] + fun(i - 1, j - 1, matrix, dp);
    int rig = matrix[i][j] + fun(i - 1, j + 1, matrix, dp);
    return dp[i][j] = max(dow, max(lef, rig));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int result = -1e8;
    for (int j = 0; j < m; j++)
    {
        result = max(result, fun(n - 1, j, matrix, dp));
    }
    return result;
}

// tabulation

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int dow = matrix[i][j] + dp[i - 1][j];
            int lef = -1e8;

            if (j - 1 >= 0)
            {
                lef = matrix[i][j] + dp[i - 1][j - 1];
            }
            int rig = -1e8;

            if (j + 1 <= m - 1)
            {
                rig = matrix[i][j] + dp[i - 1][j + 1];
            }
            dp[i][j] = max(dow, max(lef, rig));
        }
    }

    int result = -1e8;
    for (int j = 0; j < m; j++)
    {
        result = max(result, dp[n - 1][j]);
    }

    return result;
}

// space optimization

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int n = matrix.size();
    int m = matrix[0].size();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));

    vector<int> pre(m);
    vector<int> cur(m);

    for (int j = 0; j < m; j++)
    {
        pre[j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int dow = matrix[i][j] + pre[j];
            int lef = -1e8;

            if (j - 1 >= 0)
            {
                lef = matrix[i][j] + pre[j - 1];
            }
            int rig = -1e8;

            if (j + 1 <= m - 1)
            {
                rig = matrix[i][j] + pre[j + 1];
            }
            cur[j] = max(dow, max(lef, rig));
        }
        pre = cur;
    }

    int result = -1e8;
    for (int j = 0; j < m; j++)
    {
        result = max(result, pre[j]);
    }

    return result;
}