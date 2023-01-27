#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod=1e9+7;
	public:
		int CountWays(string str){
		    // Code here
		    
		    int n=str.size();
		    
		    if(str[0]=='0'){
		        return 0;
		    }
		
		    for(int i=1;i<n;i++){
		        if(str[i]=='0'){
		            
		            if(str[i-1]=='0'){
		                return 0;
		            }
		        }
		    }
		   
		    vector<int>dp(n+1,0);
		    dp[n]=1;
		  //   return fun(0,str,n,dp);
		     
		     for(int i=n-1;i>=0;i--){
		         int cnt=0;
    		    for(int j=i;j<n;j++){
    		        if(valid(i,j,str)){
    		           cnt=(cnt+dp[j+1])%mod;
    		        }
    		    }
    		    
    		     dp[i]= cnt;
		     }
		     
		     return dp[0];
		     
		}
		bool valid(int i,int j,string &str){
		    if(j-i+1>3){
		        return false;
		    }
		    string st=str.substr(i,j-i+1);
		    if(st[0]=='0'){
		        return false;
		    }
		    int num=stoi(st);
		    if(num>=1 && num<=26){
		        return true;
		    }
		    return false;
		}

};