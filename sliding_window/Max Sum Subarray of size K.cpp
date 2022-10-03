#include<bits/stdc++.h>
using namespace std;

class max_sum{
    public:
    long maximumSumSubarray(int k, vector<int> &Arr , int n){
        // code here 
        long result=INT_MIN;
        long sum=0;
        if(n<k){
            return -1;
        }
        
        int s=0;
        int e=k-1;
        
        for(int i=s;i<=e;i++){
            sum+=Arr[i];
        }
        result=max(result,sum);
        s++;
        e++;
        while(e<n){
           sum-=Arr[s-1];
           sum+=Arr[e];
           result=max(result,sum);
           s++;
           e++;
        }
        return result;
    }
};
