#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
        vector<int>mod_array(k,0);
        
        for(int i=0;i<n;i++){
            
            mod_array[arr[i]%k]++;
        }
        
        int ans=0;
        
        for(int i=0;i<k;i++){
            int cnt=mod_array[i];
            ans+=((cnt)*(cnt-1))/2;
        }
        
        return ans;
    }
};