#include<bits/stdc++.h>
using namespace std;

int maxSumBS(int arr[] , int n )
{
    vector<int>dp1(n,0);
    
    for(int i=0;i<n;i++){
        dp1[i]=arr[i];
        int max1=0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                max1=max(max1,dp1[j]);
            }
        }
        dp1[i]+=max1;
    }
    
    vector<int>dp2(n,0);
    
    for(int i=n-1;i>=0;i--){
        dp2[i]=arr[i];
        int max2=0;
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                max2=max(max2,dp2[j]);
            }
        }
        dp2[i]+=max2;
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp1[i]+dp2[i]-arr[i]);
    }
    return ans;
}