#include <bits/stdc++.h>
using namespace std;

// recursion + memoization

class Solution
{
public:
    int fun(vector<vector<int>> &grid, int row, int col1, int col2, vector<vector<vector<int>>> &dp)
    {

        if (col1 < 0 || col2 < 0 || col1 >= grid[0].size() || col2 >= grid[0].size())
        {
            return -1e8;
        }

        if (row == grid.size() - 1)
        {
            if (col1 == col2)
            {
                return grid[row][col1];
            }
            else
            {
                return grid[row][col1] + grid[row][col2];
            }
        }

        if (dp[row][col1][col2] != -1)
        {
            return dp[row][col1][col2];
        }

        int max_val = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int cher;
                if (col1 == col2)
                {
                    cher = grid[row][col1] + fun(grid, row + 1, col1 + i,
                                                 col2 + j, dp);
                }
                else
                {
                    cher = grid[row][col1] + grid[row][col2] +
                           fun(grid, row + 1, col1 + i, col2 + j, dp);
                }
                max_val = max(max_val, cher);
            }
        }
        return dp[row][col1][col2] = max_val;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col,
                                                                vector<int>(col, -1)));

        return fun(grid, 0, 0, col - 1, dp);
    }
};

//tabulation

int cherryPickup(vector<vector<int>>& grid) {
        int ro=grid.size();
        int co=grid[0].size();

        vector<vector<vector<int>>>dp(ro,vector<vector<int>>(co,
        vector<int>(co,0)));

        // return fun(grid,0,0,col-1,dp);

        for(int row=ro-1;row>=0;row--){
            for(int col1=co-1;col1>=0;col1--){
                for(int col2=0;col2<co;col2++){
                     if(row==grid.size()-1){
                        if(col1==col2){
                            dp[row][col1][col2]= grid[row][col1];
                        }
                        else{
                            dp[row][col1][col2]= grid[row][col1]+grid[row][col2];
                        }
                    }
                    else{
                        int max_val=0;
                        for(int i=-1; i<=1;i++){
                            for(int j=-1;j<=1;j++){
                                int cher=-1e7;
                              if(col1+i>=0 && col2+j>=0 && col1+i<grid[0].size()
         &&col2+j<grid[0].size()) { if(col1==col2 ){
                                    cher=grid[row][col1]+dp[row+1][col1+i]
                                    [col2+j];
                                }
                                else{
                                    cher=grid[row][col1]+grid[row][col2]+
                                    dp[row+1][col1+i][col2+j];
                                }}
                                max_val=max(max_val,cher);
                            }
                        }
                     dp[row][col1][col2]= max_val;
                    }
                }
            }
        }
        return dp[0][0][co-1];
    }