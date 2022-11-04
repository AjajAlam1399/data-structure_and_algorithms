#include<bits/stdc++.h>
using namespace std;

// memoization and recursion

int fun(int ind,int n,int buy,vector<int>&prices,vector<vector<int>>&dp){
    
    if(ind>=n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+fun(ind+1,n,0,prices,dp),fun(ind+1,n,1,
                                                         prices,dp));
    }
    else{
        profit=max(prices[ind]+fun(ind+2,n,1,prices,dp),fun(ind+1,n,0,prices,dp));
    }
    return dp[ind][buy]=profit;
}

// tabulation


int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));
//     return fun(0,n,1,prices,dp);
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
    if(buy){
        profit=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
    }
    else{
        profit=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
    }
     dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}

// space opmization

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<int>next2(2,0);
    vector<int>next1(2,0);
    vector<int>curr(2,0);


//     return fun(0,n,1,prices,dp);
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            int profit=0;
    if(buy){
        profit=max(-prices[ind]+next1[0],next1[1]);
    }
    else{
        profit=max(prices[ind]+next2[1],next1[0]);
    }
     curr[buy]=profit;
        }
        next2=next1;
        next1=curr;
    }
    return next1[1];
}