#include<bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
   vector<int>dp(n,1);
    
    int maxi=0;
    
    vector<int>hash(n);
    
    int lastindex=0;
    
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[i]>arr[prev] && dp[i]<dp[prev]+1){
                dp[i]=dp[prev]+1;
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastindex=i;
        }
    }
    int lcs[maxi];
    int ind=1;
    lcs[0]=arr[lastindex];
    while(hash[lastindex]!=lastindex){
        lastindex=hash[lastindex];
        lcs[ind++]=arr[lastindex];
    }
    sort(lcs,lcs+maxi);
    for(auto i=0;i<maxi;i++){
        cout<<lcs[i]<<" ";
    }
    cout<<endl;
  
}