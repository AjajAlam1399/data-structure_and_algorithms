#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        
        vector<string>ans;
        string subans;
        fun(0,0,n,ans,subans);
        return ans;
    }
    
    void fun(int l,int r,int n,vector<string>&ans,string subans){
        
        if(subans.size()==n*2){
            ans.push_back(subans);
            return;
        }
        
        
        if(l<n){
        
            fun(l+1,r,n,ans,subans+"(");
        }
        if(r<l){
            fun(l,r+1,n,ans,subans+")");
        }
    }
};