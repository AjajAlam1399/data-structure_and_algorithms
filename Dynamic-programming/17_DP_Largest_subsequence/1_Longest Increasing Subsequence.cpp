#include<bits/stdc++.h>
using namespace std;

// recursion + memoization

int fun(int ind,int prev,int n,int arr[], vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev+1]!=-1){
        return dp[ind][prev+1];
    }
    int not_taken=fun(ind+1,prev,n,arr,dp);
    int taken=-1e8;
    if(prev==-1 || arr[ind]>arr[prev] ){
        taken=1+fun(ind+1,ind,n,arr,dp);
    }
    return dp[ind][prev+1]= max(taken,not_taken);
}

//tabulation

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//     return fun(0,-1,n,arr,dp);
    
    for(int ind=n-1;ind>=0;ind--){
        for(int prev=n-1;prev>=-1;prev--){
            int not_taken=dp[ind+1][prev+1];
    int taken=-1e8;
    if(prev==-1 || arr[ind]>arr[prev] ){
        taken=1+dp[ind+1][ind+1];
    }
    dp[ind][prev+1]= max(taken,not_taken);
        }
    }
    
    return dp[0][-1+1];
    
}

//space optmization

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int>next(n+1,0);
        vector<int>curr(n+1,0);

//     return fun(0,-1,n,arr,dp);
    
    for(int ind=n-1;ind>=0;ind--){
        for(int prev=n-1;prev>=-1;prev--){
            int not_taken=next[prev+1];
    int taken=-1e8;
    if(prev==-1 || arr[ind]>arr[prev] ){
        taken=1+next[ind+1];
    }
    curr[prev+1]= max(taken,not_taken);
        }
        next=curr;
    }
    
    return curr[-1+1]; 
}