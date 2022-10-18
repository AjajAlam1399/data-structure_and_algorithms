#include<bits/stdc++.h>
using namespace std;

// memoization

class Solution{
public:	
	int max_sum(int *arr,int n,vector<int>&dp){
	    if(n==0){
	        dp[n]=arr[n];
	        return arr[0];
	    }
	    if(n<0){
	        return 0;
	    }
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    int pick=arr[n]+max_sum(arr,n-2,dp);
	    int not_pick=0+max_sum(arr,n-1,dp);
	    return dp[n]=max(pick,not_pick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1,-1);
	    return max_sum(arr,n-1,dp);
	}
};

// tabulation method 

