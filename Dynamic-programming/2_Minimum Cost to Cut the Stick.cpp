#include<bits/stdc++.h>
using namespace std;

// recursion and memoization

#include <bits/stdc++.h> 
int fun(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
    if(i>j) return 0;
    int ans=1e9;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    for(int k=i;k<=j;k++){
        int cost=cuts[j+1]-cuts[i-1]+fun(i,k-1,cuts,dp)+fun(k+1,j,cuts,dp);
        ans=min(ans,cost);
    }
    return dp[i][j]= ans;
    
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    
    vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
    
    return fun(1,c,cuts,dp);
}

// tabulation

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(),cuts.end());
    
    vector<vector<int>>dp(c+2,vector<int>(c+2,0));
   
//     return fun(1,c,cuts,dp);
    
    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j){
                continue;
            }
            int ans=1e9;
            for(int k=i;k<=j;k++){
                int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                ans=min(ans,cost);
            }
             dp[i][j]= ans;
        }
    }
    return dp[1][c];
}