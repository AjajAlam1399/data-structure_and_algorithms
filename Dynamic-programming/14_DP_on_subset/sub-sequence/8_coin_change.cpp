//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long fun(int ind,int tar,int coins[],vector<vector<long long>>&dp){
      
      if(tar==0){
          return 1;
      }
      
      if(ind==0){
          if(tar%coins[0]==0){
              return 1;
          }
          return 0;
      }
      
      if(dp[ind][tar]!=-1){
          return dp[ind][tar];
      }
      
      long long  not_taken=fun(ind-1,tar,coins,dp);
      
      long long taken=0;
      
      if(tar>=coins[ind]){
          taken=fun(ind,tar-coins[ind],coins,dp);
      }
      
      return dp[ind][tar]= taken+not_taken;
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        vector<long long>prev(sum+1,0);
        vector<long long>curr(sum+1,0);
        
        prev[0]=curr[0]=1;
        
        for(int tar=0;tar<=sum;tar++){
            if(tar%coins[0]==0){
                prev[tar]=1;
            }
        }
        
        for(int ind=1;ind<N;ind++){
            for(int tar=1;tar<=sum;tar++){
                  long long  not_taken=prev[tar];
      
                  long long taken=0;
                  
                  if(tar>=coins[ind]){
                      taken=curr[tar-coins[ind]];
                  }
                  
                   curr[tar]= taken+not_taken;
            }
            prev=curr;
        }
        
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends