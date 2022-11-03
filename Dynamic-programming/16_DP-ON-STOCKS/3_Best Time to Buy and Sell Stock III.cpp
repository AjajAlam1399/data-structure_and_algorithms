#include <bits/stdc++.h>
using namespace std;

//  recursion + tabulation ( not enough)

int fun(int n, int buy, int trans, vector<int> prices, int N, vector<vector<vector<int>>> &dp)
{

    if (trans == 0 || n == N)
    {
        return 0;
    }
    if (dp[n][buy][trans] != -1)
    {
        return dp[n][buy][trans];
    }
    int profit = 0;
    if (buy)
    {
        profit = max(-prices[n] + fun(n + 1, 0, trans, prices, N, dp),
                     fun(n + 1, 1, trans, prices, N, dp));
    }
    else
    {
        profit = max(prices[n] + fun(n + 1, 1, trans - 1, prices, N, dp),
                     fun(n + 1, 0, trans, prices, N, dp));
    }

    return dp[n][buy][trans] = profit;
}
int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
    return fun(0, 1, 2, prices, n, dp);
}

// tabulation
int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    //     return fun(0,1,2,prices,n,dp);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int trans = 1; trans <= 2; trans++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + dp[ind + 1][0][trans],
                                 dp[ind + 1][1][trans]);
                }
                else
                {
                    profit = max(prices[ind] + dp[ind + 1][1][trans - 1],
                                 dp[ind + 1][0][trans]);
                }

                dp[ind][buy][trans] = profit;
            }
        }
    }
    return dp[0][1][2];
}

// space optimization


