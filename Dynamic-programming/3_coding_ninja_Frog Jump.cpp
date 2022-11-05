#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int total_energy(int n,vector<int>heights,vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int left=total_energy(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1){
        right=total_energy(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    }
    return dp[n]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    
    vector<int>dp(n+1,-1);
    return total_energy(n-1,heights,dp);
}