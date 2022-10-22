#include <bits/stdc++.h>
using namespace std;

// recursion and memoziation

int min_path(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int left_dia = triangle[i][j] + min_path(triangle, i + 1, j, n, dp);
    int right_dia = triangle[i][j] + min_path(triangle, i + 1, j + 1, n, dp);
    return dp[i][j] = min(left_dia, right_dia);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int row = triangle.size();
    int col = triangle[row - 1].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));
    return min_path(triangle, 0, 0, row - 1, dp);
}

// tabualtion

 int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        int col=triangle[row-1].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        for(int i=row-1;i>=0;i--){
            for(int j=triangle[i].size()-1;j>=0;j--){
                if(i==row-1){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    int left_dia=triangle[i][j]+dp[i+1][j];
                    int right_dia=triangle[i][j]+dp[i+1][j+1];
                    dp[i][j]=min(left_dia,right_dia);
                }
            }
        }
            return dp[0][0];
    }

// space optimization

int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        int col=triangle[row-1].size();
        
        vector<int>result(triangle[row-1].begin(),triangle[row-1].end());
        
        for(int i=row-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down=triangle[i][j]+result[j];
                int diag=triangle[i][j]+result[j+1];
                result[j]=min(down,diag);
            }
        }
        return result[0];
    }