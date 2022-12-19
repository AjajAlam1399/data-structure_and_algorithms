//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long mod=1e9+7;
	int fun(int ind ,int tar,int n,int sum ,int arr[],vector<vector<int>>&dp){
	    
	    if(ind==n){
	        return tar==sum;
	    }
	    
	    if(dp[ind][tar]!=-1){
	        return dp[ind][tar];
	    }

	    int not_taken=fun(ind+1,tar,n,sum,arr,dp);
	    
	    int taken=0;
	    if(tar+arr[ind]<=sum){
	        taken=fun(ind+1,tar+arr[ind],n,sum,arr,dp);
	    }
	    
	    return dp[ind][tar]=( taken+not_taken)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        return fun(0,0,n,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends