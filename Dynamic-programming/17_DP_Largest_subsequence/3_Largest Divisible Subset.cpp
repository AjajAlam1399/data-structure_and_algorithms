#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<int>dp(n,1);
    vector<int>hash(n);
    int lastindex=0;
    int maxi=1;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[i]%arr[prev]==0 && dp[i]<dp[prev]+1){
                dp[i]=dp[prev]+1;
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastindex=i;
        }
    }
    vector<int>lcs(maxi);
    lcs[0]=arr[lastindex];
    int ind=1;
    while(hash[lastindex]!=lastindex){
        lastindex=hash[lastindex];
        lcs[ind++]=arr[lastindex];
    }
    sort(lcs.begin(),lcs.end());
    return lcs;
}
    
};