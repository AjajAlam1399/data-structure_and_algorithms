#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
        
        long long sum=0;
        long long result=INT_MIN;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(result<sum){
                result=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        
        return result;
        
    }