#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int fun(vector<int>&arr,int k){
      
      if(arr.size()==0){
          return 0;
      }
      
      vector<int>vec(arr.size()+1,0);
      
      int ans=0;
      
      int i,j,n=arr.size();
      i=j=0;
      
      while(i<n){
          vec[arr[i]]++;
          if(vec[arr[i]]==1){
              k--;
          }
          while(k<0){
              vec[arr[j]]--;
              if(vec[arr[j]]==0){
                  k++;
              }
              j++;
          }
          ans+=i-j+1;
          i++;
      }
      
      
      
      return ans;
  }
    int subarraysWithKDistinct(vector<int>& arr, int k) {
        
       return fun(arr,k)-fun(arr,k-1);
    }  
};