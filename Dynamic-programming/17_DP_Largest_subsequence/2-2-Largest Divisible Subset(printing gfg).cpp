#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        
        sort(arr.begin(),arr.end());
        
        vector<int>hash(n);
        vector<int>dp(n,1);
        
        int lastind=0;
        int size=0;
        
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>size){
                size=dp[i];
                lastind=i;
            }
        }
        
        vector<int>ans;
        
        while(lastind!=hash[lastind]){
            ans.push_back(arr[lastind]);
            lastind=hash[lastind];
        }
        
        ans.push_back(arr[lastind]);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};