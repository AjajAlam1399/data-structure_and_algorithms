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

int findMaxSum(int *arr, int n) {
	    
	    vector<int>dp(n+1,-1);
	  
	    dp[0]=arr[0];
	    dp[1]=max(arr[0],arr[1]);
	    for(int i=2;i<n;i++){
	        int pick=arr[i]+dp[i-2];
	        int not_pick=dp[i-1];
	        dp[i]=max(pick,not_pick);
	    }
	    return dp[n-1];
	}


// space optimization 


	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1,-1);
	   // return max_sum(arr,n-1,dp);
	   if(n==1){
	       return arr[0];
	   }
	   else if(n==2){
	       return max(arr[0],arr[1]);
	   }
	    int prev2=arr[0];
	    int prev1=max(arr[0],arr[1]);
	    int current;
	    for(int i=2;i<n;i++){
	        int pick=arr[i]+prev2;
	        int not_pick=prev1;
	        current=max(pick,not_pick);
	        prev2=prev1;
	        prev1=current;
	    }
	    return current;
	}

    int main(){
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }