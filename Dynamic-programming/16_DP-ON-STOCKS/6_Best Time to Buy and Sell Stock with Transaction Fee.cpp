#include <bits/stdc++.h>
using namespace std;

// recursion + memoization

int fun(int ind,int buy,int n,int fee,vector<int>prices,vector<vector<int>>&dp){
    
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit=0;
    if(buy){                        profit=max(-prices[ind]+fun(ind+1,0,n,fee,prices,dp),fun(ind+1,1,n,fee,                      prices,dp));
    }
    else{
        profit=max(prices[ind]-fee+fun(ind+1,1,n,fee,prices,dp),fun(ind+1,0,n,fee,prices,dp));
    }
    return dp[ind][buy]=profit;
}

// tabulation 

int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    vector<vector<int>>dp(n+1,vector<int>(2,0));
//     return  fun(0,1,n,fee,prices,dp);
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
    if(buy){                       
        profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
    }
    else{
        profit=max(prices[ind]-fee+dp[ind+1][1],dp[ind+1][0]);
    }
     dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}

// space opimizaton

int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    vector<int>next(2,0);
    vector<int>curr(2,0);

//     return  fun(0,1,n,fee,prices,dp);
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
    if(buy){                       
        profit=max(-prices[ind]+next[0],next[1]);
    }
    else{
        profit=max(prices[ind]-fee+next[1],next[0]);
    }
     curr[buy]=profit;
        }
        next=curr;
    }
    return next[1];
}
