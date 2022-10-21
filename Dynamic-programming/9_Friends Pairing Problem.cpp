#include<bits/stdc++.h>
using namespace std;

// momoziation
 long long mod=pow(10,9)+7;
int pairing(int n,vector<int>&dp){
       
        if(n==0){
            return 1;
        }
         if(dp[n]!=-1){
            return dp[n];
        }
        int not_pair=pairing(n-1,dp);
        int pair=0;
        if(n-1>0){
            pair=((n-1)%mod*pairing(n-2,dp)%mod)%mod;
        }
        
        return dp[n]=(pair%mod+not_pair%mod)%mod;
    }

    // tabulation

     int countFriendsPairings(int n) 
    { 
        // code her
        if(n==0){
            return 0;
        }
        vector<int>dp(n+1,-1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int not_pair=dp[i-1];
            int pair=0;
            if(i-1>0)(pair=(i-1)%mod*dp[i-2]%mod)%mod;
            dp[i]=(pair%mod+not_pair%mod)%mod;
        }
        return dp[n];
    }

    // space optimaziation

     long long mod=pow(10,9)+7;
    
    int countFriendsPairings(int n) 
    { 
        // code her
        if(n==0){
            return 0;
        }
        
        int prev2=1;
        int prev1=1;
        int current;
        
        for(int i=1;i<=n;i++){
             int not_pair=prev1;
            int pair=0;
            if(i-1>0)(pair=(i-1)%mod*prev2%mod)%mod;
            current=(pair%mod+not_pair%mod)%mod;
            prev2=prev1;
            prev1=current;
        }
        return current;
    }