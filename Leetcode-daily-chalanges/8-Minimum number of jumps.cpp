#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n<=1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int step=arr[0];
        int maxR=arr[0];
        int jump=1;
        
        for(int i=1;i<n;i++){
            if(i==n-1){
                return jump;
            }
            maxR=max(maxR,i+arr[i]);
            step--;
            if(step==0){
                jump++;
                if(i>=maxR){
                    return -1;
                }
                step=maxR-i;
            }
        }
    }
};