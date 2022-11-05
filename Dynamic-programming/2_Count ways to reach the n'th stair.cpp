//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod=pow(10,9)+7;
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int ways(int s,int e,vector<int>&dp){
        
        if(s>e){
            return 0;
        }
        
        if(s==e){
            return 1;
        }
        
        if(dp[s+1]==-1){
            dp[s+1]=ways(s+1,e,dp);
        }
        if(dp[s+2]==-1){
            dp[s+2]=ways(s+2,e,dp);
        }
        
        return(dp[s+1]+dp[s+2])%mod;
        
    }
    int countWays(int n)
    {
        // your code here
        vector<int>dp(n+2,-1);
        
        return ways(0,n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
