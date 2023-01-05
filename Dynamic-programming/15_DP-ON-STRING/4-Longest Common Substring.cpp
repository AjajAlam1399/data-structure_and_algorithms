#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<int>curr(m+1,0);
        vector<int>prev(m+1,0);
        
        int maxl=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    curr[j]=1+prev[j-1];
                    maxl=max(maxl,curr[j]);
                }
                else{
                    curr[j]=0;
                }
                
            }
            prev=curr;
        }
        
        return maxl;
    }
};