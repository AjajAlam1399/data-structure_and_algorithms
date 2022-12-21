//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  long long mod=1e9+7;
  
int fun(int ind,int tar,vector<int>& arr,vector<vector<int>>&dp){
    
      
      if(ind==0){
          
          if(tar==0 && arr[ind]==0) return 2;
          
          if(tar==0 || tar==arr[0]) return 1;
          
          return 0;
      }
      
      if(dp[ind][tar]!=-1){
          return dp[ind][tar];
      }
      
      int  not_taken=(fun(ind-1,tar,arr,dp));
      
     int taken=0;
      
      if(tar>=arr[ind]){
          taken=(fun(ind-1,tar-arr[ind],arr,dp));
      }
      
      return dp[ind][tar]=(taken+not_taken)%mod;
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int s=0;
        
        for(int i=0;i<n;i++){
            s+=arr[i];
        }
        
        int sum=((s-d)/2);
        
        if(s-d<0 || (s-d)%2!=0){
            return 0;
        }
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        return fun(n-1,sum,arr,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends