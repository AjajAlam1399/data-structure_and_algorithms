#include<bits/stdc++.h>
using namespace std;

// recursion + memoization

bool fun(int n,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0){
        return true;
    }
    if(n==0){
        return (arr[n]==target);
    }
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    bool not_take=fun(n-1,target,arr,dp);
    bool take=false;
    if(target>=arr[n]){
        take=fun(n-1,target-arr[n],arr,dp);
    }
    return dp[n][target]= take || not_take;
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    return fun(n-1,sum,arr,dp);
    }

    // tabulation

     bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool not_take=dp[i-1][j];
                bool take=false;
                if(j>=arr[i]){
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=take|| not_take;
            }
        }
        return dp[n-1][sum];
    }
    
    // space optimization

     bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<bool>pre(sum+1,false);
        vector<bool>cur(sum+1,false);
        pre[0]=cur[0]=true;
        pre[arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool not_take=pre[j];
                bool take=false;
                if(j>=arr[i]){
                    take=pre[j-arr[i]];
                }
                cur[j]=take|| not_take;
            }
            pre=cur;
        }
        return pre[sum];
    }