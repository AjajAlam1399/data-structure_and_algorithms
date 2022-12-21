#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int fun(int ind, int W, int wt[], int val[], vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (W >= wt[0])
            {
                return val[0];
            }
            return 0;
        }

        if (dp[ind][W] != -1)
        {
            return dp[ind][W];
        }

        int not_taken = fun(ind - 1, W, wt, val, dp);

        int taken = 0;

        if (W >= wt[ind])
        {
            taken = val[ind] + fun(ind - 1, W - wt[ind], wt, val, dp);
        }

        return dp[ind][W] = max(taken, not_taken);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here

        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        return fun(n - 1, W, wt, val, dp);
    }
};