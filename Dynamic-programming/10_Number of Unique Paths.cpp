#include<bits/stdc++.h>
using namespace std;

// memoization

class Solution
{
    public:
    //Function to find total number of unique paths.
    int count_path(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }
        else if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=count_path(i-1,j,dp);
        int left=count_path(i,j-1,dp);
        
        return dp[i][j]=up+left;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        
        vector<vector<int>>dp(a,vector<int>(b,-1));
        return count_path(a-1,b-1,dp);
    }
};

// tabulation

int NumberOfPath(int a, int b)
    {
        //code here
        
        vector<vector<int>>dp(a,vector<int>(b,-1));
        
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0){
                        up=dp[i-1][j];
                    }
                    if(j>0){
                        left=dp[i][j-1];
                    }
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[a-1][b-1];
    }