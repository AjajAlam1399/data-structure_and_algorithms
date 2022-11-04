#include <bits/stdc++.h> 
using namespace std;

// recursion + memoization

int fun(int ind,int n,int buy,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
    
    if(ind==n || k==0){
        return 0;
    }
    if(dp[ind][buy][k]!=-1){
        return dp[ind][buy][k];
    }
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+fun(ind+1,n,0,k,prices,dp),fun(ind+1,n,1,k,
                                                         prices,dp));
    }
    else{
        profit=max(prices[ind]+fun(ind+1,n,1,k-1,prices,dp),fun(ind+1,n,0,k,prices,dp));
    }
    return dp[ind][buy][k]=profit;
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<vector<int>>>dp(n+1,vector<vector
                               <int>>(2,vector<int>(k+1,-1)));
    return fun(0,n,1,k,prices,dp);
}


// tabulation

int maximumProfit(vector<int> &prices, int n, int trans)
{
    // Write your code here.
    vector<vector<vector<int>>>dp(n+1,vector<vector
                               <int>>(2,vector<int>(trans+1,0)));
//     return fun(0,n,1,k,prices,dp);
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=trans;k++){
                int profit=0;
    if(buy){
        profit=max(-prices[ind]+dp[ind+1][0][k],dp[ind+1][1][k]);
    }
    else{
        profit=max(prices[ind]+dp[ind+1][1][k-1],dp[ind+1][0][k]);
    }
     dp[ind][buy][k]=profit;
            }
        }
    }
    return dp[0][1][trans];
}

// space optimization

int maximumProfit(vector<int> &prices, int n, int trans)
{
    // Write your code here.
    vector<vector<int>>curr(2,vector<int>(trans+1,0));
        vector<vector<int>>next(2,vector<int>(trans+1,0));

//     return fun(0,n,1,k,prices,dp);
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int k=1;k<=trans;k++){
                int profit=0;
    if(buy){
        profit=max(-prices[ind]+next[0][k],next[1][k]);
    }
    else{
        profit=max(prices[ind]+next[1][k-1],next[0][k]);
    }
     curr[buy][k]=profit;
            }
        }
        next=curr;
    }
    return next[1][trans];
}

