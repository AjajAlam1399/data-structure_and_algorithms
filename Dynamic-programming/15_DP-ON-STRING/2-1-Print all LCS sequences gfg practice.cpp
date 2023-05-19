#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[101][101];
    int fin_l=0;
    vector<string>ans;
	public:
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    
		    int x=s.size();
		    int y=t.size();
		    
		    memset(dp,-1,sizeof(dp));
		    
		    fin_l=lcs(0,0,s,t);
		    
	
		    
		    fun(0,0,s,t,"",0);
		    
		    return ans;
		}
		
		
		int lcs(int i,int j,string &s,string &t){
		    
		    if(i==s.size() || j==t.size()){
		        return 0;
		    }
		    if(dp[i][j]!=-1){
		        return dp[i][j];
		    }
		    if(s[i]==t[j]){
		        
		        return dp[i][j]= 1+ lcs(i+1,j+1,s,t);
		    }
		    
		    return  dp[i][j]=max(lcs(i+1,j,s,t),lcs(i,j+1,s,t));
		}
		
		
		void fun(int pos1,int pos2,string &s,string &t,string subans,int curr_l){
		    
		    
		    if(curr_l==fin_l){
		        ans.push_back(subans);
		        return;
		    }
		    if(pos1==s.size() || pos2==t.size()){
		        return ;
		    }
		    
		    for(char ch='a' ;ch<='z';ch++){
		        bool f=false;
		        
		        for(int i=pos1;i<s.size();i++){
		            if(ch==s[i]){
		                
		                for(int j=pos2;j<t.size();j++){
		                    
		                    if(ch==t[j] && lcs(i,j,s,t)==fin_l-curr_l){
		                        string newstr=subans+ch;
		                        fun(i+1,j+1,s,t,newstr,curr_l+1);
		                        f=true;
		                        break;
		                    }
		                }
		            }
		            if(f){
		                break;
		            }
		        }
		    }
		}
};