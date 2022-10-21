#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int path_count(vector<vector<int>>obst_grid,int row,int col,vector<vector<int>>&dp){
        if((row>=0 && col>=0)&&(obst_grid[row][col]==1)){
            return 0;
        }
        if(row==0 && col==0){
            return 1;
        }
        if(row<0 || col<0){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int up=path_count(obst_grid,row-1,col,dp);
        int right=path_count(obst_grid,row,col-1,dp);
        
        return dp[row][col]=up+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return path_count(obstacleGrid,row-1,col-1,dp);
    }
};