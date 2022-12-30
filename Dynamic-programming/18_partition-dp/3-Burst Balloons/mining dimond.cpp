#include <bits/stdc++.h>
using namespace std;

// memoization + recursion

class Solution
{
public:
    int fun(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {

        if (i > j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int maxcoins = -1e7;
        for (int k = i; k <= j; k++)
        {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] +
                        fun(i, k - 1, nums, dp) + fun(k + 1, j, nums, dp);
            maxcoins = max(maxcoins, coins);
        }

        return dp[i][j] = maxcoins;
    }
    int maxCoins(vector<int> &nums)
    {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return fun(1, n - 2, nums, dp);
    }
};

// tabulation

int maxCoins(vector<int> &nums)
{

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // return fun(1,n-2,nums,dp);

    for (int i = n - 2; i >= 1; i--)
    {
        for (int j = i; j <= n - 2; j++)
        {
            int maxcoins = -1e7;
            for (int k = i; k <= j; k++)
            {
                int coins = nums[i - 1] * nums[k] * nums[j + 1] +
                            dp[i][k - 1] + dp[k + 1][j];
                maxcoins = max(maxcoins, coins);
            }

            dp[i][j] = maxcoins;
        }
    }
    return dp[1][n - 2];
}