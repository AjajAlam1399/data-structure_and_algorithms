#include <bits/stdc++.h> 
using namespace std;
bool cmp(string s1,string s2){
    return s1.size()<s2.size();
}

bool compare(string &s1,string &s2){
    if(s1.size()!=s2.size()+1){
        return false;
    }
    int ind1=0;
    int ind2=0;
    while(ind1<s1.size()){
        if(s1[ind1]==s2[ind2]){
            ind1++;
            ind2++;
        }
        else{
            ind1++;
        }
    }
    if(ind1==s1.size() && ind2==s2.size()){
        return true;
    }
    return false;
}
int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    int n=arr.size();
    sort(arr.begin(),arr.end(),cmp);
    vector<int>dp(n,1);
    
    int maxi=1;
    
    for(int i=1;i<n;i++){
        for(int prev=0;prev<i;prev++){
            if(compare(arr[i],arr[prev])  && dp[i]<dp[prev]+1){
                dp[i]=dp[prev]+1;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
        }
    }
    
    return maxi;
    
}