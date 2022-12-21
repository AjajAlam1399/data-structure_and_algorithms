//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  
    int fun(int ind,int tar,vector<int>&A,vector<vector<int>>&dp){
        
        if(ind==0){
            if(tar==0 && A[0]==0) return 2;
        if(tar==0 || A[ind]==tar) return 1;
        
        return 0;
        }
        
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        
        int not_taken=fun(ind-1,tar,A,dp);
        
        int taken=0;
        
        if(tar>=A[ind]){
            
            taken=fun(ind-1,tar-A[ind],A,dp);
        }
        
        return dp[ind][tar]= taken+not_taken;
    }
    
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        
        int n=A.size();
        
        int s=0;
        
        for(int i=0;i<n;i++){
            s+=A[i];
        }
        
        if(s-target<0 || (s-target)%2!=0){
            return 0;
        }
        
        vector<vector<int>>dp(n,vector<int>((s-target)/2+1,-1));
        
        return fun(n-1,(s-target)/2,A,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends