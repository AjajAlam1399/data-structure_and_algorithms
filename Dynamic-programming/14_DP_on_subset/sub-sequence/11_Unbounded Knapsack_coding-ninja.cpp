#include <bits/stdc++.h>
using namespace std;

// recursion and memoizaton

int fun(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (weight[0] <= w)
        {
            int times = (w / weight[0]);
            return times * profit[0];
        }
        else
            return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    int not_taken = fun(n - 1, w, profit, weight, dp);
    int taken = -1e8;
    if (weight[n] <= w)
    {
        taken = profit[n] + fun(n, w - weight[n], profit, weight, dp);
    }
    return dp[n][w] = max(not_taken, taken);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return fun(n - 1, w, profit, weight, dp);
}

// tabulation

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    //     return fun(n-1,w,profit,weight,dp);

    for (int i = 0; i <= w; i++)
    {
        if (weight[0] <= i)
        {
            int times = (i / weight[0]);
            dp[0][i] = times * profit[0];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int tar = 0; tar <= w; tar++)
        {
            int not_taken = dp[i - 1][tar];
            int taken = -1e8;
            if (weight[i] <= tar)
            {
                taken = profit[i] + dp[i][tar - weight[i]];
            }
            dp[i][tar] = max(not_taken, taken);
        }
    }
    return dp[n - 1][w];
}

    // space optimization

    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
    {
        // Write Your Code Here.
        //     return fun(n-1,w,profit,weight,dp);
        vector<int> prev(w + 1, 0);
        vector<int> curr(w + 1, 0);
        for (int i = 0; i <= w; i++)
        {
            if (weight[0] <= i)
            {
                int times = (i / weight[0]);
                prev[i] = times * profit[0];
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int tar = 0; tar <= w; tar++)
            {
                int not_taken = prev[tar];
                int taken = -1e8;
                if (weight[i] <= tar)
                {
                    taken = profit[i] + curr[tar - weight[i]];
                }
                curr[tar] = max(not_taken, taken);
            }
            prev = curr;
        }
        return prev[w];
    }