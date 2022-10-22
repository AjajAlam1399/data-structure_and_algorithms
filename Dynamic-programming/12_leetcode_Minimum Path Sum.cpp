#include <bits/stdc++.h>
using namespace std;

// recursion + memoization

class Solution
{
public:
    int mincost(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp)
    {

        if (row == 0 && col == 0)
        {
            return grid[row][col];
        }
        if (row < 0 || col < 0)
        {
            return 1e9;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        long long up = grid[row][col] + (long long)mincost(grid, row - 1, col, dp);
        long long left = grid[row][col] + (long long)mincost(grid, row, col - 1, dp);
        return dp[row][col] = min(up, left);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return mincost(grid, row - 1, col - 1, dp);
    }
};

// tabulation

    int minPathSum(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));
    // return mincost(grid,row-1,col-1,dp);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
            }
            else
            {
                int up=INT_MAX;
                int left=INT_MAX;
                
                if (i > 0)
                {
                    up = grid[i][j] + dp[i - 1][j];
                }
                if (j > 0)
                {
                   left = grid[i][j] + dp[i][j - 1];
                }
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[row - 1][col - 1];
    }