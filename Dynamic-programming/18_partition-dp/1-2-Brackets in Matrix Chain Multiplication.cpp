#include<bits/stdc++.h>
using namespace std;

class Solution{
    
public:
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<pair<string,int>>>dp(n,vector<pair<string,int>>(n,{"",-1}));
        auto it=fun(1,n-1,p,dp);
        return it.first;
    }
    
    pair<string,int> fun(int i,int j,int p[],vector<vector<pair<string,int>>>&dp){
        
        
        if(i==j){
            string s="";
            s+='A'+i-1;
            return {s,0};
        }
        
        if(dp[i][j].second!=-1){
            return dp[i][j];
        }
        
        int ans=1e9;
        string ansstr="";
        for(int k=i;k<j;k++){
            auto left=fun(i,k,p,dp);
            auto right=fun(k+1,j,p,dp);
            int currans=left.second+right.second+p[i-1]*p[k]*p[j];
            string s="";
            s+="("+left.first+right.first+")";
            if(ans>currans){
                ansstr=s;
                ans=currans;
            }
        }
         dp[i][j]= {ansstr,ans};
         return dp[i][j];
    }
};