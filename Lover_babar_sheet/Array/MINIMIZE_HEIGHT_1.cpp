#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        
        sort(arr,arr+n);
        int min_height=arr[0];
        int max_height=arr[n-1];
        int result=max_height-min_height;
        
        for(int i=1;i<n;i++){
            min_height=min(arr[0]+k,arr[i]-k);
            max_height=max(arr[i-1]+k,arr[n-1]-k);
            // if(min_height<0) continue;
            result=min(result,max_height-min_height);
        }
        return result;
    }
};