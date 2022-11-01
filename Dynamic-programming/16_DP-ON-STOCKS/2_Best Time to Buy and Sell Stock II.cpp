#include <bits/stdc++.h>
using namespace std;

// memoization and recursion

long fun(int i, int buy, long *value, int n, vector<vector<long>> &dp)
{

    if (i == n)
    {
        return 0;
    }
    if (dp[i][buy] != -1)
    {
        return dp[i][buy];
    }
    long profit = 0;
    if (buy)
    {
        profit = max(-value[i] + fun(i + 1, 0, value, n, dp), fun(i + 1, 1, value, n, dp));
    }
    else
    {
        profit = max(value[i] + fun(i + 1, 1, value, n, dp), fun(i + 1, 0, value, n, dp));
    }

    return dp[i][buy] = profit;
}

// tabulation

long getMaximumProfit(long *values, int n)
{
    // Write your code here

    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    //     return fun(0,1,values,n,dp);

    dp[n][0] = 0;
    dp[n][1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            long profit = 0;
            if (j)
            {
                profit = max(-values[i] + dp[i + 1][0], dp[i + 1][1]);
            }
            else
            {
                profit = max(values[i] + dp[i + 1][1], dp[i + 1][0]);
            }
            dp[i][j] = profit;
        }
    }
    return dp[0][1];
}

// space optimization

long getMaximumProfit(long *values, int n)
{
    vector<long>next(2,0);
    vector<long>curr(2,0);
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=1;j++){
             long profit=0;
    if(j){
        profit=max(-values[i]+ next[0],next[1]);
    }
    else{
        profit=max(values[i]+next[1],next[0]);
    }
     curr[j]= profit;
        }
        next=curr;
    } 
    return curr[1];   
}