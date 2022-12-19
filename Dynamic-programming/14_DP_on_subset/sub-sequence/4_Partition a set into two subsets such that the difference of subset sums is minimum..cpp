//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    
	    vector<vector<int>>dp(n,vector<int>(sum+1,0));
	    
	    
	    
	    if(arr[0]<=sum){
	        dp[0][arr[0]]=1;
	    }
	    
	    
	    for(int ind=1;ind<n;ind++){
	        for(int k=0;k<=sum;k++){
	            bool not_taken=dp[ind-1][k];
                bool taken=false;
                
                if(k>=arr[ind]){
                    taken=dp[ind-1][k-arr[ind]];
                }
                
             dp[ind][k]=taken || not_taken;
	        }
	    }
	    
	    
	    vector<int>result;
	    
	    for(int i=0;i<=sum;i++){
	        if(dp[n-1][i]==1){
	            result.push_back(i);
	        }
	    }
	    
	    int ans=1e8;
	    
	    for(int i=0;i<result.size();i++){
	        int s1=result[i];
	        int s2=sum-s1;
	        
	        ans=min(ans,abs(s1-s2));
	    }
	    
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends