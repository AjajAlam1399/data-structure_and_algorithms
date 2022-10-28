#include <bits/stdc++.h>
using namespace std;

// recursion  + memoization

int fun(int n, int tar, int price[], vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return tar * price[0];
    }
    int not_taken = fun(n - 1, tar, price, dp);
    int taken = -1e8;
    if (dp[n][tar] != -1)
    {
        return dp[n][tar];
    }
    if (n <= tar - 1)
    {
        taken = price[n] + fun(n, tar - 1 - n, price, dp);
    }
    return dp[n][tar] = max(taken, not_taken);
}
int cutRod(int price[], int n)
{
    // code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    // return fun(n-1,n,price,dp)
}

// tabulation

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    //     return fun(n-1,n,price,dp);
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int tar = 0; tar <= n; tar++)
        {
            int not_taken = dp[i - 1][tar];
            int taken = -1e8;
            if (i <= tar - 1)
            {
                taken = price[i] + dp[i][tar - 1 - i];
            }
            dp[i][tar] = max(taken, not_taken);
        }
    }
    return dp[n - 1][n];
}

// space optimization

int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    //     return fun(n-1,n,price,dp);
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int tar = 0; tar <= n; tar++)
        {
            int not_taken = prev[tar];
            int taken = -1e8;
            if (i <= tar - 1)
            {
                taken = price[i] + curr[tar - 1 - i];
            }
            curr[tar] = max(taken, not_taken);
        }
        prev = curr;
    }
    return prev[n];
}